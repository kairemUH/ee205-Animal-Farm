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

#include <stdexcept>
#include <iostream>
#include <iomanip>

#include "Cat.h"

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
