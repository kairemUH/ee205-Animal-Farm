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

#include <iostream>
#include <cassert>

#include "catDatabase.h"
#include "addCats.h"


bool addCat( Cat* newCat ) {

    assert( newCat->catIsValid() );

    if( isCatInDatabase( newCat ) ) {
        throw std::logic_error( "Cat already in database." );
    }

    newCat->next = catDatabaseHeadPointer ;
    catDatabaseHeadPointer = newCat ;

    assert( validateDatabase() );

    return true;

}

