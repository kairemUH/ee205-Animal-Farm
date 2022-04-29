///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Animal Farm 3 - EE 205 - Spr 2022
///
/// @file Animal.cpp
/// @version 1.0
///
/// @author Kai Matsusaka <kairem@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "Animal.h"



const std::string Animal::KINGDOM_NAME = "Animalia";


////////////////////  Constructors  ////////////////////

Animal::Animal( Weight newMaxWeight, const std::string &newClassification, const std::string &newSpecies ) {

    if( newMaxWeight.validate() && validateClassification(newClassification) && validateSpecies(newSpecies) ) {

        Animal::gender = Gender::UNKNOWN_GENDER;
        Animal::weight.setMaxWeight( newMaxWeight.getWeight( Animal::weight.getWeightUnit() ) );
        Animal::classification = newClassification;
        Animal::species = newSpecies;

    }

}


Animal::Animal( const Gender newGender, const Weight newWeight, const Weight newMaxWeight, const std::string &newClassification, const std::string &newSpecies ) {

    if( newMaxWeight.validate() && newWeight.validate() && validateClassification(newClassification) && validateSpecies(newSpecies) ) {

        Animal::gender = newGender;
        Animal::weight.setWeight( newWeight.getWeight( Animal::weight.getWeightUnit() ) );
        Animal::weight.setMaxWeight( newMaxWeight.getWeight( Animal::weight.getWeightUnit() ) );
        Animal::classification = newClassification;
        Animal::species = newSpecies;

    }

}



////////////////////  Getters and Setters  ////////////////////

std::string Animal::getKingdom() const noexcept {
    return Animal::KINGDOM_NAME;
}


std::string Animal::getClassification() const noexcept {
    return Animal::classification;
}


std::string Animal::getSpecies() const noexcept {
    return Animal::species;
}


Gender Animal::getGender() const noexcept {
    return Animal::gender;
}


Weight Animal::getWeight() const noexcept {
    return Animal::weight;
}


void Animal::setWeight( const Weight newWeight ) {
    if( newWeight.validate() ) {
        Animal::weight = newWeight;
    }
}


void Animal::setGender( const Gender newGender ) {
    Animal::gender = newGender;
}



////////////////////  Dump and Validation  ////////////////////

void Animal::dump() const noexcept {

    Node::dump();
    FORMAT_LINE_FOR_DUMP( "Animal", "kingdom" ) << KINGDOM_NAME << std::endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "species" ) << species << std::endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "classification" ) << classification << std::endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "gender" ) << gender << std::endl ;
    weight.dump();

}


bool Animal::validateClassification( const std::string &checkClassification ) noexcept {

    if( checkClassification.empty() ) {
        return false;
    }

    return true;

}


bool Animal::validateSpecies( const std::string &checkSpecies ) noexcept {

    if( checkSpecies.empty() ) {
        return false;
    }

    return true;

}


bool Animal::validate() const noexcept {

    if( Node::validate() && Animal::weight.validate() && validateClassification(Animal::classification) &&
            validateSpecies(Animal::species) ) {
        return true;
    }

    return false;

}