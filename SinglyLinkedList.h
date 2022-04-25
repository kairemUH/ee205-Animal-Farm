///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Animal Farm 3 - EE 205 - Spr 2022
///
/// @file SinglyLinkedList.h
/// @version 1.0
///
/// @author Kai Matsusaka <kairem@hawaii.edu>
/// @date   25_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "List.h"

class SinglyLinkedList : public List {

////////////////////  Constructors  ////////////////////
public:
    SinglyLinkedList() = default;


////////////////////  Functions  ////////////////////
public:
    void  push_front( Node* newNode );  // Insert `newNode` to the beginning of the List
    Node* pop_front() noexcept override; // Remove and return the first Node in the List
    void insert_after( Node* currentNode, Node* newNode );  // Insert `newNode` after `currentNode`
    void dump() const noexcept override;     // Output the contents of this container
    bool validate() const noexcept override;

};

