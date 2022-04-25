///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Animal Farm 2 - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author Kai Matsusaka <kairem@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cassert>
#include <cstring>

#include "config.h"
#include "Cat.h"
#include "SinglyLinkedList.h"

#define ILLEGAL_NAME "12345678901234567890123456789012345678901234567890"

//#define DEBUG

int main() {

    std::cout << "Starting Animal Farm 2" << std::endl;


    Cat Bob = Cat( "Bob", Color::BLUE, true, Gender::MALE, 1.2);

    SinglyLinkedList listOne = SinglyLinkedList();

    listOne.push_front( &Bob );

    Bob.dump();

    Cat Joe = Cat( "Joe" );
    Joe.setColor( Color::WHITE );

    Joe.dump();

    listOne.push_front( &Joe );

    listOne.dump();

    assert( listOne.isIn(&Joe) );
    assert( listOne.isIn(&Bob) );


    try {
        Bob.setName(nullptr);
        assert(false); // We should never get here
    } catch (std::exception const &e) {}

    try {
        Bob.setName(ILLEGAL_NAME);
        assert(false); // We should never get here
    } catch (std::exception const &e) {}

    try {
        listOne.push_front( &Bob );
        assert(false); // We should never get here
    } catch (std::exception const &e) {}

    assert( listOne.size() == 2 );

    std::cout << std::endl;


    // start of main from spec

    SinglyLinkedList catDB ;
    catDB.push_front( new Cat( "Loki", Color::WHITE, true, Gender::MALE, 1.0 ) ) ;
    catDB.push_front( new Cat( "Milo", Color::BLACK, true, Gender::MALE, 1.1 ) ) ;
    catDB.push_front( new Cat( "Bella", Color::GREEN, true, Gender::FEMALE, 1.2 ) ) ;
    catDB.push_front( new Cat( "Kali", Color::RED, true, Gender::FEMALE, 1.3 ) ) ;
    catDB.push_front( new Cat( "Trin", Color::WHITE, true, Gender::FEMALE, 1.4 ) ) ;
    catDB.insert_after(catDB.get_first(), new Cat( "Chili", Color::RED, true, Gender::MALE, 1.5 ) );

    for( Animal* pAnimal = (Animal*)catDB.get_first() ; pAnimal != nullptr ; pAnimal = (Animal*)List::get_next( (Node*)pAnimal ) ) {
        std::cout << pAnimal->speak() << std::endl;
    }

    catDB.validate() ;
    catDB.dump() ;
    catDB.deleteAllNodes() ;
    catDB.dump() ;


    std::cout << "Done with Animal Farm 3" << std::endl;

    return( EXIT_SUCCESS ) ;
}
