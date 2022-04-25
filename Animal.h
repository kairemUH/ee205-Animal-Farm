///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  animalFarm2 - EE 205 - Spr 2022
///
/// @file Animal.h
/// @version 1.0
///
/// @author Kai Matsusaka <kairem@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "config.h"
#include "Node.h"
#include "Gender.h"
#include "Color.h"
#include "Weight.h"

#include <iostream>
#include <cstring>


class Animal : public Node {

////////////////////  Member Variables  ////////////////////
public:
    static const std::string KINGDOM_NAME;

private:
    std::string species;
    std::string classification;
    Gender gender;
    Weight weight;

////////////////////  Constructors  ////////////////////
public:
    Animal( const Weight newMaxWeight, const std::string &newClassification, const std::string &newSpecies );

    Animal( const Gender newGender, const Weight newWeight, const Weight newMaxWeight, const std::string &newClassification, const std::string &newSpecies );



////////////////////  Getters and Setters  ////////////////////
public:
    std::string getKingdom() const noexcept;
    std::string getClassification() const noexcept;
    std::string getSpecies() const noexcept;
    Gender getGender() const noexcept;
    Weight getWeight() const noexcept;
    void setWeight( const Weight newWeight );
    virtual std::string speak() const noexcept=0;

protected:
    void setGender( const Gender newGender );



////////////////////  Dump and Validation  ////////////////////
public:
    void dump() const noexcept override;
    static bool validateClassification( const std::string &checkClassification ) noexcept;
    static bool validateSpecies( const std::string &checkSpecies ) noexcept;
    bool validate() const noexcept override;

};

