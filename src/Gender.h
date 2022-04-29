///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Animal Farm 3 - EE 205 - Spr 2022
///
/// @file Gender.h
/// @version 1.0
///
/// @author Kai Matsusaka <kairem@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>

enum class Gender { UNKNOWN_GENDER, MALE, FEMALE };

// operator override to print out enums
inline std::ostream& operator<<( std::ostream& lhs_stream, const Gender& rhs_Gender ){
    switch( rhs_Gender ) {
        case Gender::UNKNOWN_GENDER:
            lhs_stream << "Unknown gender";
            break;
        case Gender::MALE:
            lhs_stream << "Male";
            break;
        case Gender::FEMALE:
            lhs_stream << "Female";
            break;
        default:
            /// @throw out_of_range If the enum is not mapped to a string.
            throw std::out_of_range( "Gender not mapped to a string" );
    }
    return lhs_stream;
}
