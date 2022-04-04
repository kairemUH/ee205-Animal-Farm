///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Animal Farm 2 - EE 205 - Spr 2022
///
/// @file reportCats.cpp
/// @version 1.0
///
/// @author Kai Matsusaka <kairem@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cassert>
#include <cstring>

#include "reportCats.h"
#include "catDatabase.h"


Cat* findCatByName( const char name[] ) {

    assert( Cat().nameIsValid(name) );

    for(Cat* iCat = catDatabaseHeadPointer ; iCat != nullptr ; iCat = iCat->next ) {
        if( std::strcmp( name, iCat->getName() ) == 0 ) {
            return iCat ;
        }
    }

    return nullptr;
}


void printAllCats() {

    assert( validateDatabase() );

    for(Cat* iCat = catDatabaseHeadPointer ; iCat != nullptr ; iCat = iCat->next ) {
        iCat->print() ;
    }

}


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


