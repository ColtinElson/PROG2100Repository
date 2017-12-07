cmake_minimum_required(VERSION 3.8)
project(Final)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp City.cpp Human.cpp GameSpecs.cpp Organism.cpp Zombie.cpp)
add_executable(Final ${SOURCE_FILES})