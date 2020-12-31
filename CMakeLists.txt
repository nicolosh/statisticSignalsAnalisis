cmake_minimum_required(VERSION 3.17)
project(statisticSignalsAnalisis)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(statisticSignalsAnalisis main.cpp
        src/signals.cpp
        src/statistic.cpp
        )