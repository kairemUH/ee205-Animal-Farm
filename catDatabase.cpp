///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Animal Farm 2 - EE 205 - Spr 2022
///
/// @file catDatabase.cpp
/// @version 1.0
///
/// @author Kai Matsusaka <kairem@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cassert>

#include "config.h"
#include "catDatabase.h"
#include "addCats.h"
#include "reportCats.h"
#include "deleteCats.h"


Cat* catDatabaseHeadPointer = nullptr;


bool isCatInDatabase( const Cat* cat ) {

    if( cat == nullptr || !validateDatabase() ) {
        return false;
    }

    for( Cat* iCat = catDatabaseHeadPointer; iCat != nullptr; iCat = iCat->next ) {
        if( iCat == cat ) {
            return true ;
        }
    }

    assert( validateDatabase() ) ;

    return false ;

}


bool validateDatabase() {

    for( Cat* iCat = catDatabaseHeadPointer; iCat != nullptr; iCat = iCat->next ) {
        if( ! iCat->catIsValid() ) {
            return false;
        }
    }

    return true;

}