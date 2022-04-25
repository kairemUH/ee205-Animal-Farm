///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  animalFarm2 - EE 205 - Spr 2022
///
/// @file Color.h
/// @version 1.0
///
/// @author Kai Matsusaka <kairem@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>

enum class Color { BLACK, WHITE, RED, BLUE, GREEN, PINK };

// operator override to print out enums
inline std::ostream& operator<<( std::ostream& lhs_stream, const Color& rhs_Color ){
    switch( rhs_Color ) {
        case Color::BLACK:
            lhs_stream << "Black";
            break;
        case Color::WHITE:
            lhs_stream << "White";
            break;
        case Color::RED:
            lhs_stream << "Red";
            break;
        case Color::BLUE:
            lhs_stream << "Blue";
            break;
        case Color::GREEN:
            lhs_stream << "Green";
            break;
        case Color::PINK:
            lhs_stream << "Pink";
            break;
        default:
            /// @throw out_of_range If the enum is not mapped to a string.
            throw std::out_of_range( "Color not mapped to a string" );
    }
    return lhs_stream;
}
