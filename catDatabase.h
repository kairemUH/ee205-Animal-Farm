///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author Kai Matsusaka <kairem@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#define MAX_CAT 1024
#define MAX_CAT_NAME 50

typedef float Weight;

typedef int NumCats;



enum Gender {UNKNOWN_GENDER, MALE, FEMALE};

enum Breed {UNKNOWN_BREED, MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHYNX};

enum Color {BLACK, WHITE, RED, BLUE, GREEN, PINK};

struct Cat {

    char name[MAX_CAT_NAME];
    enum Gender gender;
    enum Breed breed;
    bool isFixed;
    Weight weight;
    enum Color collarColor1;
    enum Color collarColor2;
    unsigned long long license;

};


extern struct Cat catArray[MAX_CAT];

extern NumCats numCats;


extern const char* genderName( enum Gender gender );

extern const char* breedName( enum Breed breed );

extern const char* colorName( enum Color color );


extern bool nameIsValid( const char name[] );

extern bool nameInDatabase( const char name[] );

extern bool weightIsValid( Weight weight );

extern bool isFull();

extern bool indexIsValid( int index );

//@todo add initialize database funciton that memsets the arrays to zero
