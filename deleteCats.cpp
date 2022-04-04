///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Animal Farm 2 - EE 205 - Spr 2022
///
/// @file deleteCats.cpp
/// @version 1.0
///
/// @author Kai Matsusaka <kairem@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cassert>

#include "deleteCats.h"
#include "catDatabase.h"


bool deleteCat( Cat* cat ) {

    assert( cat != nullptr );
    assert( validateDatabase() );

    //special case for cat being first in database
    if( cat == catDatabaseHeadPointer ) {
        catDatabaseHeadPointer = catDatabaseHeadPointer->next;
        delete cat;
        return true;
    }


    Cat* iCat = catDatabaseHeadPointer ;

    while( iCat != nullptr ) {

        if (iCat->next == cat) {    // check for cat

            iCat->next = cat->next;     // cut cat out of database
            delete cat;                 // free up the memory

            assert( validateDatabase() );
            return true;

        }

        iCat = iCat->next;  // iterate

    }

    throw std::invalid_argument( "Cat is not in database." );

}


bool deleteAllCats() {

    while( catDatabaseHeadPointer != nullptr ) {    // iterate through database deleting all cats
        deleteCat (catDatabaseHeadPointer);
    }

    return true;

}
