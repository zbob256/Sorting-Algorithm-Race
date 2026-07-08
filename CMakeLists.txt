cmake_minimum_required(VERSION 3.10)
project(Sorting-Algorithm-Race)

add_executable(Sorting-Algorithm-Race
    src/main.cpp
    src/dataset.cpp
    src/algorithm.cpp
    src/list.cpp

    src/sorts/bubble.cpp
    src/sorts/bucket.cpp
    src/sorts/cocktailshaker.cpp
    src/sorts/comb.cpp
    src/sorts/counting.cpp
    src/sorts/gnome.cpp
    src/sorts/heap.cpp
    src/sorts/insertion.cpp
    src/sorts/intro.cpp
    src/sorts/merge.cpp
    src/sorts/oddeven.cpp
    src/sorts/quick.cpp
    src/sorts/radix.cpp
    src/sorts/selection.cpp
    src/sorts/shell.cpp
    src/sorts/tim.cpp
    src/sorts/verify.cpp
)

target_include_directories(Sorting-Algorithm-Race PRIVATE
    include
)

target_compile_options(Sorting-Algorithm-Race PRIVATE)
