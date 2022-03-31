///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file updateCats.h
/// @version 1.0
///
/// @author Kai Matsusaka <kairem@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

extern int updateCatName( int index, const char newName[] );

extern int fixCat( int index );

extern int updateCatWeight( int index, Weight newWeight );

extern void updateCatCollar1( int index, enum Color collar1 );

extern void updateCatCollar2( int index, enum Color collar2 );

extern void updateLicense( int index, unsigned long long license );

