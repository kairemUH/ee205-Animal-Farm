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

#include "config.h"

class Cat {

////////// Member Variables //////////
protected:
    char name[MAX_CAT_NAME];
    enum Gender gender;
    enum Breed breed;
    bool fixed;
    Weight weight;

public:
    Cat *next;


////////// Constructors //////////
public:
    Cat();

    Cat(const char n[], enum Gender g, enum Breed b, bool fix, Weight w);


////////// Getters and Setters //////////
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


////////// Print and Validation //////////
public:
    bool print();

    bool catIsValid();

    bool nameIsValid(const char name[]);

    bool weightIsValid(Weight weight);

    bool genderIsValid(enum Gender gender);

    bool breedIsValid(enum Breed breed);


////////// Private Functions //////////
private:
    void zeroOutMemberData();

};