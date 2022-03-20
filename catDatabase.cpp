///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.cpp
/// @version 1.0
///
/// @author Kai Matsusaka <kairem@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "catDatabase.h"
#include "addCats.h"
#include "reportCats.h"
#include "updateCats.h"
#include "deleteCats.h"

struct Cat catArray[MAX_CAT]; //Cat Database

int numCats = 0;              //The high water mark for the array (The number of cats in the array)


////////////////////  Enum Functions  ////////////////////

const char* genderName( enum Gender gender ) {

    switch (gender) {
        case 0:
            return "Unknown Gender";
            break;
        case 1:
            return "Male";
            break;
        case 2:
            return "Female";
            break;
        default:
            return "Unknown Gender";
            break;
    }

}


const char* breedName( enum Breed breed ) {

    switch (breed) {
        case 0:
            return "Unknown Breed";
            break;
        case 1:
            return "Maine Coon";
            break;
        case 2:
            return "Manx";
            break;
        case 3:
            return "Shorthair";
            break;
        case 4:
            return "Persian";
            break;
        case 5:
            return "Sphynx";
            break;
        default:
            return "Unknown Gender";
            break;
    }

}


const char* colorName( enum Color color ) {

    switch (color) {
        case 0:
            return "Black";
            break;
        case 1:
            return "White";
            break;
        case 2:
            return "Red";
            break;
        case 3:
            return "Blue";
            break;
        case 4:
            return "Green";
            break;
        case 5:
            return "Pink";
            break;
        default:
            return "Unknown Color";
            break;
    }

}


////////////////////  Validation Functions  ////////////////////

bool nameIsValid( const char name[] ) {

    if( strlen(name) < 1 ) {

        fprintf( stderr, "Cat name cannot be empty.\n" );
        return false;

    }

    if ( strlen(name) > MAX_CAT_NAME ) {

        fprintf( stderr, "Cat name [%s] must be shorter than or equal to [%d] characters.\n", name, MAX_CAT_NAME );
        return false;

    }

    return true;

}


bool nameInDatabase( const char name[] ) {

    for ( int i = 0; i < numCats; i++ ) {

        if( strcmp(catArray[i].name, name) == 0 ) {

            fprintf( stderr, "Cat name [%s] already in database.\n", name );
            return true;

        }

    }

    return false;

}


bool weightIsValid( float weight ) {

    if ( weight <= 0 ) {

        fprintf( stderr, "Cat weight [%f] must be greater than zero.\n", weight );
        return false;

    }

    return true;

}


bool isFull() {

    if ( numCats >= MAX_CAT ) {

        fprintf( stderr, "Database is Full.\n" );
        return true;

    }

    return false;

}


bool indexIsValid( int index ) {

    if( numCats == 0 ) {
        fprintf( stderr, "Cat Database is empty.\n" );
        return false;
    }

    if( index < 0 || index > numCats ) {
        fprintf( stderr, "Animal Farm 1: Bad Cat! Index [%d] must be greater than zero.\n", index );
        return false;
    }

    if( index < 0 || index > numCats ) {
        fprintf( stderr, "Animal Farm 1: Bad Cat! Index [%d] must be less than [%d]\n", index, numCats );
        return false;
    }

    return true;

}

