cmake_minimum_required(VERSION 3.22)
project(animalFarm)

set(CMAKE_CXX_STANDARD 14)

add_executable(animalFarm main.cpp addCats.cpp addCats.h catDatabase.cpp catDatabase.h deleteCats.cpp deleteCats.h reportCats.cpp reportCats.h Cat.cpp Cat.h config.h Gender.h Color.h Node.cpp Node.h Animal.cpp Animal.h Weight.cpp Weight.h)
