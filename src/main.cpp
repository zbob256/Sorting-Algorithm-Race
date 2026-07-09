#include <iostream>
#include <iomanip>
#include <algorithm>
#include "algorithm.hpp"
#include "sorts.hpp"
#include "list.hpp"
#include "dataset.hpp"

int currentRank = 1;
int currentFailRank = 1;

void update() {
    std::cout << "\033[H";

    std::cout << "Size: " << ELEMENTS << " elements. Range: " << MIN << " to " << MAX << ". Neatness: " << NEATNESS << "." << std::endl;
    
    std::cout << "\n";

    std::cout << std::left
        << std::setw(10) << "Rank"
        << std::setw(25) << "Algorithm Name"
        << std::setw(20) << "Thread ID"
        << std::setw(20) << "Time (s)"
        << std::setw(20) << "Operations"
        << std::setw(20) << "Status"
        << "\n\n";

    std::vector<std::reference_wrapper<Algorithm>> sorted(algorithms.begin(), algorithms.end());

    std::sort(sorted.begin(), sorted.end(), [](Algorithm &a, Algorithm &b) {
        bool aFailed = a.status == "Failed";
        bool bFailed = b.status == "Failed";

        if (aFailed != bFailed) return bFailed;
        if (aFailed && bFailed) return a.rank < b.rank;

        bool aUnranked = a.rank == -1;
        bool bUnranked = b.rank == -1;
        
        if (aUnranked != bUnranked) return bUnranked;
        if (aUnranked && bUnranked) return false;

        return a.rank < b.rank;
    });

    for (Algorithm &algorithm : algorithms) {
        if (algorithm.status == "Running") {
            auto now = std::chrono::steady_clock::now();
            algorithm.time = std::chrono::duration<float>(now - algorithm.startTime).count();
        }
    }

    for (Algorithm &algorithm : sorted) {
        std::cout << std::left << std::setw(10);

        if (algorithm.rank == -1 || algorithm.status == "Failed") {
            if (algorithm.status == "Failed") {
                std::cout << "N/A";
            } else {
                std::cout << "...";
            }
        } else {
            std::cout << algorithm.rank;
        }

        std::cout << std::left << std::setw(25) << algorithm.name;

        if (algorithm.id == std::thread::id()) {
            std::cout << std::left << std::setw(20) << "...";
        } else {
            std::cout << std::left << std::setw(20) << algorithm.id;
        }
    
        std::cout << std::left << std::setw(20) << std::fixed << std::setprecision(5) << algorithm.time;
        std::cout << std::left << std::setw(20) << algorithm.operations;
        std::cout << std::left << std::setw(20) << algorithm.status;
        std::cout << "\n";
    }

    std::cout << "\n\n\n";
}

bool stillRunning() {
    bool anyRunning = false;
    std::vector<Algorithm*> newlyFinished;

    for (Algorithm &algorithm : algorithms) {
        if (algorithm.status == "Finished" || algorithm.status == "Failed") {
            if (algorithm.rank == -1) {
                auto now = std::chrono::steady_clock::now();
                algorithm.time = std::chrono::duration<float>(now - algorithm.startTime).count();
                newlyFinished.push_back(&algorithm);

                
            }
        } else {
            anyRunning = true;
        }
    }

    std::sort(newlyFinished.begin(), newlyFinished.end(), [](Algorithm* a, Algorithm* b) {
        return a->time < b->time;
    });

    for (Algorithm* algorithm : newlyFinished) {
        if (algorithm->status == "Failed") {
            algorithm->rank = currentFailRank;
            currentFailRank++;
        } else {
            algorithm->rank = currentRank;
            currentRank++;
        }
    }

    return anyRunning;
}

int main() {
    std::cout << "\033[2J\033[3J\033[H";

    update();

    std::cout << "Press Enter to start the race: ";
    std::cin.get();

    std::cout << "\033[?25l\033[2J\033[3J\033[H";

    std::vector<std::thread> threads;

    for (Algorithm &algorithm : algorithms) {
        threads.emplace_back(algorithm.function, dataset);
    }

    while (stillRunning()) {
        update();
    }

    update();

    for (auto &t : threads) {
        t.join();
    }

    std::cout << "\033[?25h";
}
