///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Animal Farm 2 - EE 205 - Spr 2022
///
/// @file Cat.cpp
/// @version 1.0
///
/// @author Kai Matsusaka <kairem@hawaii.edu>
/// @date   02_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cstring>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <cassert>

#include "Cat.h"
#include "reportCats.h"

const std::string Cat::SPECIES_NAME = "Felis catus";
const Weight Cat::MAX_WEIGHT = Weight(40);   // 40 pounds


////////////////////  Constructors  ////////////////////
Cat::Cat( const std::string &newName ) : Mammal( MAX_WEIGHT, SPECIES_NAME ), name( newName ), isCatFixed( false ) {}

Cat::Cat( const std::string &newName, const Color newColor, const bool newIsFixed, const Gender newGender, const Weight newWeight ) :
Mammal( newColor, newGender, newWeight, MAX_WEIGHT, SPECIES_NAME ), name( newName ), isCatFixed( newIsFixed ) {}



////////////////////  Getters and Setters  ////////////////////

std::string Cat::getName() const noexcept {
    return Cat::name;
}


void Cat::setName( const std::string &newName ) {
    if( validateName(newName) ) {
        Cat::name = newName;
    }
}


bool Cat::isFixed() const noexcept {
    return Cat::isCatFixed;
}


void Cat::fixCat() noexcept {
    Cat::isCatFixed = true;
}



////////////////////  Dump and Speak Functions  ////////////////////

std::string Cat::speak() const noexcept {

    std::cout << "Meow" << std::endl;

}


void Cat::dump() const noexcept {

    Mammal::dump();
    FORMAT_LINE_FOR_DUMP( "Cat", "Name" ) << Cat::name << std::endl;
    FORMAT_LINE_FOR_DUMP( "Cat", "Is Fixed" ) << Cat::isCatFixed << std::endl;

}



////////////////////  Validation Functions  ////////////////////

bool Cat::validate() const noexcept {

    if( Mammal::validate() && validateName(Cat::name) ) {
        return true;
    }

    return false;

}


bool Cat::validateName( const std::string &newName ) {

    if( newName.empty() ) {
        throw std::length_error( "Cat name cannot be empty.");
    }

    if( newName.length() >= MAX_NAME ) {
        throw std::length_error( "Name must be less than MAX_CAT_NAME." );
    }

    return true;
}



/*
#define FORMAT_LINE( className, member ) std::cout << std::setw(8) << (className) << std::setw(20) << (member) << std::setw(52)

void Cat::zeroOutMemberData() {
    std::memset(name, 0, MAX_CAT_NAME);
    gender = UNKNOWN_GENDER;
    breed = UNKNOWN_BREED;
    fixed = false;
    weight = UNKNOWN_WEIGHT;
    next = nullptr;
}


////////////////////  Constructors  ////////////////////

Cat::Cat() {
    zeroOutMemberData();
}

Cat::Cat(const char *n, enum Gender g, enum Breed b, Weight w) {
    if( nameIsValid(n) && genderIsValid(g) && breedIsValid(b) && weightIsValid(w) ) {
        strcpy(Cat::name, n);
        Cat::gender = g;
        Cat::breed = b;
        Cat::weight = w;
    }

    assert( catIsValid() == true );
}


////////////////////  Getters  ////////////////////

char* Cat::getName() {
    return Cat::name;
}

enum Gender Cat::getGender() {
    return Cat::gender;
}

enum Breed Cat::getBreed() {
    return Cat::breed;
}

bool Cat::isFixed() {
    return Cat::fixed;
}

Weight Cat::getWeight() {
    return Cat::weight;
}


////////////////////  Setters  ////////////////////

void Cat::setName( const char newName[] ) {
    if( nameIsValid(newName) ) {
        strcpy(Cat::name, newName);
    }
}

void Cat::setGender(enum Gender newGender) {
    if( Cat::gender == UNKNOWN_GENDER && genderIsValid(newGender) ) {
        Cat::gender = newGender;
    }
    else {
        throw std::invalid_argument( "Cat gender already set." );
    }
}

void Cat::setBreed(enum Breed newBreed) {
    if( Cat::breed == UNKNOWN_BREED && breedIsValid(newBreed) ) {
        Cat::breed = newBreed;
    }
    else {
        throw std::invalid_argument( "Cat breed already set." );
    }
}

void Cat::fixCat() {
    Cat::fixed = true;
}

void Cat::setWeight(Weight newWeight) {
    if( weightIsValid(newWeight) ){
        Cat::weight = newWeight;
    }
}


////////////////////  Print and Validation  ////////////////////



bool Cat::print() {
    assert( Cat::catIsValid() == true ) ;

    std::cout << std::setw(80) << std::setfill( '=' ) << "" << std::endl ;
    std::cout << std::setfill( ' ' ) ;
    std::cout << std::left ;
    std::cout << std::boolalpha ;
    FORMAT_LINE( "Cat", "name" )         << getName()   << std::endl ;
    FORMAT_LINE( "Cat", "gender" )       << genderName( getGender() ) << std::endl ;
    FORMAT_LINE( "Cat", "breed" )        << breedName( getBreed() )   << std::endl ;
    FORMAT_LINE( "Cat", "isFixed" )      << isFixed()   << std::endl ;
    FORMAT_LINE( "Cat", "weight" )       << getWeight() << std::endl ;

    return true ;
}

bool Cat::catIsValid() {
    if( nameIsValid(Cat::name) && weightIsValid(Cat::weight) && genderIsValid(Cat::gender) && breedIsValid(Cat::breed) ) {
        return true;
    }

    return false;
}

bool Cat::nameIsValid(const char name[]) {
    if( name == NULL ) {
        throw std::invalid_argument( "Name must not be NULL." );
    }

    if( strlen( name ) < 1 ) {
        throw std::length_error( "Cat name cannot be empty.");
    }

    if( strlen( name ) >= MAX_CAT_NAME ) {
        throw std::length_error( "Name must be less than MAX_CAT_NAME." );
    }

    return true;
}

bool Cat::weightIsValid(Weight weight) {
    if( weight <= 0 ) {
        throw std::invalid_argument( "Cat weight must be greater than zero." );
    }

    return true;
}

bool Cat::genderIsValid(enum Gender gender) {
    if( gender == UNKNOWN_GENDER ) {
        throw std::invalid_argument( "Gender must be known.");
    }

    return true;
}

bool Cat::breedIsValid(enum Breed breed) {
    if( breed == UNKNOWN_BREED ) {
        throw std::invalid_argument("Breed must be known.");
    }

    return true;
}
*/
