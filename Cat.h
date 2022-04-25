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

class Cat : Mammal {

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

/*
class Cat {

////////////////////  Member Variables  ////////////////////
protected:
    char name[MAX_CAT_NAME];
    enum Gender gender;
    enum Breed breed;
    bool fixed;
    Weight weight;

public:
    Cat *next;


////////////////////  Constructors  ////////////////////
public:
    Cat();

    Cat(const char n[], enum Gender g, enum Breed b, Weight w);


////////////////////  Getters and Setters  ////////////////////
public:
    char *getName();

    enum Gender getGender();

    enum Breed getBreed();

    bool isFixed();

    Weight getWeight();

    void setName( const char newName[] );

    void setGender(enum Gender newGender);

    void setBreed(enum Breed newBreed);

    void fixCat();

    void setWeight(Weight newWeight);


////////////////////  Print and Validation  ////////////////////
public:
    bool print();

    bool catIsValid();

    bool nameIsValid(const char name[]);

    bool weightIsValid(Weight weight);

    bool genderIsValid(enum Gender gender);

    bool breedIsValid(enum Breed breed);


////////////////////  Private Functions  ////////////////////
private:
    void zeroOutMemberData();

}; */
