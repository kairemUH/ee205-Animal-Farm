///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Animal Farm 2 - EE 205 - Spr 2022
///
/// @file reportCats.h
/// @version 1.0
///
/// @author Kai Matsusaka <kairem@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "config.h"
#include "Cat.h"


extern Cat* findCatByName( const char name[] );

extern void printAllCats();


////////////////////  Enum Functions  ////////////////////
extern const char* genderName( enum Gender gender );
extern const char* breedName( enum Breed breed );
extern const char* colorName( enum Color color );



