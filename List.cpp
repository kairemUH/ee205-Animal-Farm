///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  animalFarm - EE 205 - Spr 2022
///
/// @file List.cpp
/// @version 1.0
///
/// @author Kai Matsusaka <kairem@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>

#include "List.h"

////////////////////  Public Functions  ////////////////////

bool List::empty() const noexcept {
    return List::head == nullptr;
}


unsigned int List::size() const noexcept {
    return List::count;
}


bool List::isIn( Node *aNode ) const {

    for(Node* iNode = List::head ; iNode != nullptr ; iNode = iNode->Node::next ) {
        if( aNode == iNode ) {
            return true;
        }
    }

    return false;

}


bool List::isSorted() const noexcept {

    Node* temp = head;

    for( Node* iNode = List::head->Node::next ; iNode != nullptr ; iNode = iNode->Node::next ) {

        if( temp > iNode ) { return false; }

        temp = iNode;

    }

    return true;

}


Node * List::get_first() const noexcept {
    return List::head;
}


void List::deleteAllNodes() noexcept {

    assert( validate() );
    while( head != nullptr ) {
        pop_front();
    }
#ifdef DEBUG
    cout << PROGRAM_NAME << ": All Nodes have been deleted" << endl ;
#endif
    assert( validate() );

}



////////////////////  Static Functions  ////////////////////

Node * List::get_next( const Node *currentNode ) {
    return currentNode->next;
}