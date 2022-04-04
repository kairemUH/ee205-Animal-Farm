///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Animal Farm 2 - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author Kai Matsusaka <kairem@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Cat.h"

extern Cat* catDatabaseHeadPointer;

extern bool isCatInDatabase( const Cat* cat );  // returns true if cat is in database

extern bool validateDatabase();     // returns true if database is valid

extern bool isDatabaseEmpty();      // returns true if database is empty

//@todo future implementation of duplicate name checking
//@todo add initialize database funciton that memsets the arrays to zero


