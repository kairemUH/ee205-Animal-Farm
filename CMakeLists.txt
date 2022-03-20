cmake_minimum_required(VERSION 3.22)
project(animalFarm1)

set(CMAKE_CXX_STANDARD 14)

add_executable(animalFarm1 main.cpp addCats.cpp addCats.h catDatabase.cpp catDatabase.h deleteCats.cpp deleteCats.h reportCats.cpp reportCats.h updateCats.cpp updateCats.h)
