///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  animalFarm2 - EE 205 - Spr 2022
///
/// @file Node.h
/// @version 1.0
///
/// @author Kai Matsusaka <kairem@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#ifndef HEADERFILE_H
#define HEADERFILE_H

class Node {

    friend class List;
    friend class SinglyLinkedList;

////////////////////  Member Variable  ////////////////////
protected:
    Node* next = nullptr;


////////////////////  Functions  ////////////////////
protected:
    static bool compareByAddress ( const Node* node1, const Node* node2 );

public:
    virtual void dump() const;
    virtual bool validate() const noexcept;
    virtual bool operator>(const Node& rightSide);

};

#endif
