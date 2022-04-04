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

#include "catDatabase.h"
#include "addCats.h"
#include "reportCats.h"
#include "deleteCats.h"
#include "config.h"
#include "Cat.h"

#define ILLEGAL_NAME "12345678901234567890123456789012345678901234567890"

//#define DEBUG

int main() {
    std::cout << "Starting Animal Farm 2" << std::endl;

#ifdef DEBUG
    {
        Cat testCat = Cat();
      // Verify that a cat's default values are set
      try {
          assert(testCat.getName() != nullptr);
          assert(strcmp(testCat.getName(), "") == 0);
          assert(testCat.getGender() == UNKNOWN_GENDER);
          assert(testCat.getBreed() == UNKNOWN_BREED);
          assert(testCat.isFixed() == false);
          assert(testCat.getWeight() == UNKNOWN_WEIGHT);
          assert(!testCat.isFixed());
          assert(!testCat.catIsValid());  // The default cat is invalid
      } catch (std::exception const &e) {}
      std::cout << "default values are set" << std::endl;

      // Test for NULL name
      try {
         testCat.setName(nullptr);
         assert(false); // We should never get here
      } catch (std::exception const &e) {}
      std::cout << "tested for null name" << std::endl;

      // Test for empty name
      try {
         testCat.setName("");
         assert(false); // We should never get here
      } catch (std::exception const &e) {}
      std::cout << "tested for empty name" << std::endl;

      // Test valid names
      testCat.setName("A");       // A 1 character name is valid
      testCat.setName("Be");     // A 2 character name is valid
      std::cout << "tested for valid names" << std::endl;

      // Test for name too large
      try {
         testCat.setName(ILLEGAL_NAME);
         assert(false); // We should never get here
      } catch (std::exception const &e) {}
      std::cout << "tested for too large names" << std::endl;

      testCat.setGender(FEMALE);

      try {
         testCat.setGender(MALE);
         assert(false); // We should never get here
      } catch (std::exception const &e) {}
      std::cout << "tested set gender" << std::endl;

      testCat.setBreed(MAINE_COON);

      try {
         testCat.setBreed(MANX);
         assert(false); // We should never get here
      } catch (std::exception const &e) {}
      std::cout << "tested set breed" << std::endl;

      testCat.fixCat();
      assert(testCat.isFixed());
      std::cout << "tested fix cat" << std::endl;

      // Test for Weight <= 0
      try {
         testCat.setWeight(0);
         assert(false); // We should never get here
      } catch (std::exception const &e) {}

      testCat.setWeight(1.0 / 1024);
      assert(testCat.getWeight() == 1.0 / 1024);
      std::cout << "tested set weight" << std::endl;

      assert(testCat.catIsValid());  // The cat should now be valid
      testCat.print();
      std::cout << "tested print cat" << std::endl;

      assert(!isCatInDatabase(&testCat)) ;
   }
#endif

    bool result ;
    result = addCat( new Cat( "Loki", MALE, PERSIAN, 1.0 )) ;
    assert( result ) ;
    if( !result ) throw std::logic_error ( "addCat() failed" ) ;
    result = addCat( new Cat( "Milo", MALE, MANX , 1.1 )) ;
    assert( result ) ;
    result = addCat( new Cat( "Bella", FEMALE, MAINE_COON, 1.2 )) ;
    assert( result ) ;
    result = addCat( new Cat( "Kali", FEMALE, SHORTHAIR, 1.3 )) ;
    assert( result ) ;
    result = addCat( new Cat( "Trin", FEMALE, MANX, 1.4 )) ;
    assert( result ) ;
    result = addCat( new Cat( "Chili", MALE, SHORTHAIR, 1.5 )) ;
    assert( result ) ;

#ifdef DEBUG
    {
      // Test finding a cat...
      Cat *bella = findCatByName("Bella");
      assert(bella != nullptr);
      // Test not finding a cat
      assert(findCatByName("Bella's not here") == nullptr);
      std::cout << "tested find cat" << std::endl;

      // Test deleting a cat...
      assert(deleteCat(bella) == true);
      try {
         deleteCat(bella); // Verify that Bella's not there
      } catch (std::exception const &e) {}

      bella = nullptr;
      std::cout << "tested delete cat" << std::endl;
   }
#endif

    printAllCats() ;

    deleteAllCats() ;

    printAllCats() ;

    std::cout << "Done with Animal Farm 2" << std::endl;

    return( EXIT_SUCCESS ) ;
}

