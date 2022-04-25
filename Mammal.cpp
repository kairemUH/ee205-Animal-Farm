///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  animalFarm - EE 205 - Spr 2022
///
/// @file Mammal.cpp
/// @version 1.0
///
/// @author Kai Matsusaka <kairem@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "Mammal.h"

const std::string Mammal::MAMMAL_NAME = "Mammalia";

////////////////////  Constructors  ////////////////////

Mammal::Mammal( const Weight newMaxWeight, const std::string &newSpecies ) : Animal( newMaxWeight, MAMMAL_NAME, newSpecies ) {}


Mammal::Mammal( const Color newColor, const Gender newGender, const Weight newWeight, const Weight newMaxWeight, const std::string &newSpecies ) :
Animal ( newGender, newWeight, newMaxWeight, MAMMAL_NAME, newSpecies ), color(newColor) {}



////////////////////  Getters and Setters  ////////////////////

Color Mammal::getColor() const noexcept {
    return Mammal::color;
}


void Mammal::setColor(const Color newColor) noexcept {
    Mammal::color = newColor;
}



////////////////////  Dump  ////////////////////

void Mammal::dump() const noexcept {

    Animal::dump();
    FORMAT_LINE_FOR_DUMP( "Mammal", "Color" ) << Mammal::color << std::endl;

}