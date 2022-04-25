///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Animal Farm 3 - EE 205 - Spr 2022
///
/// @file Node.cpp
/// @version 1.0
///
/// @author Kai Matsusaka <kairem@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "Node.h"
#include "config.h"

#include <iostream>

bool Node::compareByAddress ( const Node* node1, const Node* node2 ) {

    if ( node1 > node2 ) { return true; }
    else { return false; }

}


void Node::dump() const {

    PRINT_HEADING_FOR_DUMP;
    FORMAT_LINE_FOR_DUMP( "Node", "this" ) << this << std::endl ;
    FORMAT_LINE_FOR_DUMP( "Node", "next" ) << next << std::endl ;

}


bool Node::validate() const noexcept {

    if ( next == nullptr ) {
        return true;
    }

    if ( this == this->next ) {
        std::cout << "Recursive loop detected:  next points to itself!" ;
        return false;
    }

    return true;

}


bool Node::operator>(const Node& rightSide) {

    return compareByAddress( this, &(Node&)rightSide );

}