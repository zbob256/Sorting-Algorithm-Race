#pragma once

#include <iostream>
#include <thread>
#include <functional>
#include <vector>

class Algorithm {
    public:
        int rank;
        std::string name;
        std::thread::id id;
        float time;
        long long int operations;
        std::string status;
        std::function<void(std::vector<int>)> function;
        std::chrono::steady_clock::time_point startTime;

        Algorithm(int rank, std::string name, std::thread::id id, std::string status, std::function<void(std::vector<int>)> function);
};