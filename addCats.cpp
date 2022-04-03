///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Animal Farm 2 - EE 205 - Spr 2022
///
/// @file addCats.cpp
/// @version 1.0
///
/// @author Kai Matsusaka <kairem@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "catDatabase.h"
#include "addCats.h"

int addCat( const char n[], enum Gender g, enum Breed b, bool fix, Weight w, enum Color collar1, enum Color collar2, unsigned long long license ) {


    if( isFull() || nameInDatabase(n) || ! nameIsValid(n) || ! weightIsValid(w) ) {

        return 0;

    }

    else {

        strcpy( catArray[numCats].name, n );
        catArray[numCats].gender = g;
        catArray[numCats].breed = b;
        catArray[numCats].isFixed = fix;
        catArray[numCats].weight = w;
        catArray[numCats].collarColor1 = collar1;
        catArray[numCats].collarColor2 = collar2;
        catArray[numCats].license = license;

        numCats++;  //increment the index of the arrays.

    }

    return numCats;

}

