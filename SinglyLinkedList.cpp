///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  animalFarm - EE 205 - Spr 2022
///
/// @file SinglyLinkedList.cpp
/// @version 1.0
///
/// @author Kai Matsusaka <kairem@hawaii.edu>
/// @date   25_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cassert>

#include "SinglyLinkedList.h"


////////////////////  Functions  ////////////////////

void  SinglyLinkedList::push_front( Node* newNode ) {

    assert( newNode->validate() );

    if( isIn(newNode) ) {
        throw std::logic_error( "Node already in database." );
    }

    newNode->next = head;
    head = newNode;

    assert( SinglyLinkedList::validate() );

    List::count ++;

}


Node* SinglyLinkedList::pop_front() noexcept {

    assert( head != nullptr );
    assert( SinglyLinkedList::validate() );

    Node*& iNode = head;
    head = head->next;

    assert( SinglyLinkedList::validate() );

    return iNode;   // @todo should delete old head


}


void SinglyLinkedList::insert_after( Node* currentNode, Node* newNode ) {

    assert( SinglyLinkedList::validate() );
    assert( newNode->validate() );

    if( isIn(newNode) ) {
        throw std::logic_error( "Node already in database." );
    }

    if( ! isIn(currentNode) ) {
        throw std::logic_error( "Current node is not in database." );
    }

    newNode->next = currentNode->next;
    currentNode->next = newNode;
    List::count ++;

}


void SinglyLinkedList::dump() const noexcept {

    for(Node* iNode = List::head ; iNode != nullptr ; iNode = iNode->next ) {
        iNode->dump();
    }

}


bool SinglyLinkedList::validate() const noexcept {

    for(Node* iNode = List::head ; iNode != nullptr ; iNode = iNode->next ) {

        if( ! iNode->validate() ) { return false; }

    }

    return true;

}