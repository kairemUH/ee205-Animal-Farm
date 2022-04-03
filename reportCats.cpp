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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "reportCats.h"
#include "catDatabase.h"


int printCat( int index ) {

    if( ! indexIsValid(index) ) {
        return 0;
    }

    else {
        printf( "cat index = [%d]  ",      index );
        printf( "name = [%s]  ",           catArray[index].name );
        printf( "gender = [%s]  ",         genderName(catArray[index].gender) );
        printf( "breed = [%s]  ",          breedName(catArray[index].breed) );
        printf( "isFixed = [%d]  ",        catArray[index].isFixed );
        printf( "weight = [%f]  ",         catArray[index].weight );
        printf( "collar 1 color = [%s]  ", colorName(catArray[index].collarColor1) );
        printf( "collar 2 color = [%s]  ", colorName(catArray[index].collarColor2) );
        printf( "license = [%llu]  ",      catArray[index].license );
        printf( "\n" );
    }

    return 1;

}


void printAllCats() {

    for(int i = 0; i < numCats; i++) {
        printf( "cat index = [%d]  ",      i );
        printf( "name = [%s]  ",           catArray[i].name );
        printf( "gender = [%s]  ",         genderName(catArray[i].gender) );
        printf( "breed = [%s]  ",          breedName(catArray[i].breed) );
        printf( "isFixed = [%d]  ",        catArray[i].isFixed );
        printf( "weight = [%f]  ",         catArray[i].weight );
        printf( "collar 1 color = [%s]  ", colorName(catArray[i].collarColor1) );
        printf( "collar 2 color = [%s]  ", colorName(catArray[i].collarColor2) );
        printf( "license = [%llu]  ",      catArray[i].license );
        printf( "\n" );
    }

}


int findCat( const char n[] ) {

    if( ! nameIsValid(n) ) {
        return -1;
    }

    else {

        for( int i = 0; i < numCats; i++ ) {

            if ( strcmp(catArray[i].name, n) == 0 ) {
                return i;
            }

        }

    }

    fprintf(stderr, "Cat [%s] not in database.\n", n);
    return -1;

}

