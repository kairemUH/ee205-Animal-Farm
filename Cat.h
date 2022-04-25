///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Animal Farm 2 - EE 205 - Spr 2022
///
/// @file Cat.h
/// @version 1.0
///
/// @author Kai Matsusaka <kairem@hawaii.edu>
/// @date   02_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "config.h"
#include "Mammal.h"

class Cat : public Mammal {

////////////////////  Member Variables  ////////////////////
public:
    static const std::string SPECIES_NAME;
    static const Weight MAX_WEIGHT;

protected:
    std::string name;
    bool isCatFixed;


////////////////////  Constructors  ////////////////////
public:
    Cat(const std::string &newName);
    Cat(const std::string &newName, const Color newColor, const bool newIsFixed, const Gender newGender, const Weight newWeight);


////////////////////  Getters and Setters  ////////////////////
public:
    std::string getName() const noexcept;
    void setName(const std::string &newName);
    bool isFixed() const noexcept;
    void fixCat() noexcept;


////////////////////  Dump and Speak Functions  ////////////////////
public:
    std::string speak() const noexcept override;
    void dump() const noexcept override;


////////////////////  Validation Functions  ////////////////////
public:
    bool validate() const noexcept override;
    static bool validateName(const std::string &newName);

};
