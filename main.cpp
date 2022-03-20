///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file main.cpp
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

//#define DEBUG

int main() {

    addCat( "Loki", MALE, PERSIAN, true, 8.5, BLACK, WHITE, 101 ) ;
    addCat( "Milo", MALE, MANX, true, 7.0, BLACK, RED, 102 ) ;
    addCat( "Bella", FEMALE, MAINE_COON, true, 18.2, BLACK, BLUE, 103 ) ;
    addCat( "Kali", FEMALE, SHORTHAIR, false, 9.2, BLACK, GREEN, 104 ) ;
    addCat( "Trin", FEMALE, MANX, true, 12.2, BLACK, PINK, 105 ) ;
    addCat( "Chili", UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, BLACK, 106 ) ;
    printAllCats();

    updateCatCollar1( 1, GREEN );
    printCat( 1 );

    int kali = findCat( "Kali" ) ;

#ifdef DEBUG
    printf("Kali's index: [%d] \n", kali);
#endif

    printCat( kali );
    updateCatName( kali, "Capulet" ) ;
    updateCatWeight( kali, 9.9 ) ;
    fixCat( kali ) ;
    printCat( kali );
    printAllCats();
    deleteAllCats();
    printAllCats();


#ifdef DEBUG
    addCat( "Loki", MALE, PERSIAN, true, 8.5, BLACK, WHITE, 101 );
    addCat( "Milo", MALE, MANX, true, 7.0, BLACK, RED, 102 );

    printCat( findCat( "Loki" ) );

    updateCatName( findCat( "Loki" ), "Milo" );  //should cause error [cat name already in database]

    updateCatName( findCat( "Loki" ), "Yolo" );

    printCat( -1 );
    printCat( findCat( "Yolo" ) );
    printCat( findCat( "Loki" ) );   //error

    printCat( findCat( "Milo" ) );
#endif

    return EXIT_SUCCESS;

}

