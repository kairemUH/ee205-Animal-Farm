///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file updateCats.cpp
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
#include "updateCats.h"

int updateCatName( int index, const char newName[] ) {


    if( ! nameIsValid(newName) || nameInDatabase(newName) || ! indexIsValid(index) ) {
        return 0;
    }

    else {
        strcpy(catArray[index].name, newName);
    }

    return 1;

}


int fixCat( int index ) {

    if( ! indexIsValid(index) ) {
        return 0;
    }

    else {
        catArray[index].isFixed = true;
    }

    return 1;

}


int updateCatWeight( int index, float newWeight ) {

    if( ! indexIsValid(index) || ! weightIsValid(newWeight) ) {
        return 0;
    }

    else {
        catArray[index].weight = newWeight;
    }

    return 1;

}


void updateCatCollar1( int index, enum Color collar1 ) {

    catArray[index].collarColor1 = collar1;

}


void updateCatCollar2( int index, enum Color collar2 ) {

    catArray[index].collarColor2 = collar2;

}

void updateLicense( int index, unsigned long long license ) {

    catArray[index].license = license;

}
