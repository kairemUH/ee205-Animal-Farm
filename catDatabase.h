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



extern Cat* catDatabaseHeadPointer;
extern bool isCatInDatabase( const Cat* cat );
extern bool validateDatabase();

//@todo future implementation of duplicate name checking
//@todo add initialize database funciton that memsets the arrays to zero


