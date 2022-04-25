///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  animalFarm - EE 205 - Spr 2022
///
/// @file Mammal.h
/// @version 1.0
///
/// @author Kai Matsusaka <kairem@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>

#include "Animal.h"
#include "Color.h"
#include "Gender.h"

class Mammal : public Animal {

////////////////////  Member Variables  ////////////////////
public:
    static const std::string MAMMAL_NAME;

protected:
    Color color;


////////////////////  Constructors  ////////////////////
public:
    Mammal(const Weight newMaxWeight, const std::string &newSpecies);
    Mammal(const Color newColor, const Gender newGender, const Weight::t_weight newWeight, const Weight::t_weight newMaxWeight, const std::string &newSpecies);


////////////////////  Getters and Setters  ////////////////////
public:
    Color getColor() const noexcept;
    void setColor(const Color newColor) noexcept;


////////////////////  Dump  ////////////////////
public:
    void dump() const noexcept override;


};
