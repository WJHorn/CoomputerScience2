/*
   COPYRIGHT (C) 2016 William Horn (wjh27) All rights reserved.
   CSII assignment 5 A
   Author.  William Horn
            wjh27@zips.uakron.edu
   Version. 1.01 09.09.2017

*/
// Implementation file for the NumberList class

#include <iostream>
#include "charList.hpp"


//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
// pre: an empty parameter list                    *
// post: standard output of the linked list        *
//**************************************************

void CharList::displayList() const
{
   ListNode *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;
   short count = 0;

   // While nodePtr points to a node, traverse
   // the list.
   while (nodePtr)
   {
      // Display the value in this node.
      std::cout << "[" << nodePtr->value << "] -> ";
      ++count;
      // Move to the next node.
      nodePtr = nodePtr->next;
      if (count % 10 == 0) {
        std::cout << std::endl;
        count = 0;
      }
   }
   std::cout << std::endl;
}


//**************************************************
// appendNode                                      *
// This function appends a node to the end of the  *
// list. contains a char value.                    *
// pre: contains a char to be appended to the list *
// post: appends new node to end of list           *
//**************************************************

void CharList::appendNode(char val)
{
    //pointer for a new node
    ListNode *newNode;
    //pointer to move through the list.
    ListNode *nodePtr;

    //create a new node and store the character there
    newNode = new ListNode;
    newNode->value = val;
    newNode->next = nullptr;

    //if there are no nodes, new node is the new head
    if(!head)
    {
        head = newNode;
    }
    else    //else, insert newNode at the end.
    {
        //start at the head
        nodePtr = head;

        //move to the end of the list
        while(nodePtr->next)
        {
            nodePtr = nodePtr->next;
        }

        //insert newNode to the end.
        nodePtr->next = newNode;
    }
}


//**************************************************
// insertNode                                      *
// This function inserts a node with the char      *
// parameter's value copied to its char member     *
// element.                                        *
// pre: contains a char to be inserted             *
// post: inserts char into list                    *
//**************************************************

void CharList::insertNode(char val)
{
    //new node
    ListNode *newNode;
    //used to move through list
    ListNode *nodePtr;
    //the previous node (initialized to nullptr)
    ListNode *previousNode = nullptr;

    // allocate new node and store the character in it
    newNode = new ListNode;
    newNode->value = val;

    //if there are no nodes in the list, make newNode the head
    if(!head)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    else //else, insert the new node
    {
        //start at the head
        nodePtr = head;
        //initialize previousNode to nullptr
        previousNode = nullptr;

        //skip nodes that have a lesser value than the one stored in newNode
        while (nodePtr != nullptr && nodePtr->value < val)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        //if the new node is first in the list, put it first
        if(previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else    //else, insert after the previous node
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}


//**************************************************
// deleteNode                                      *
// This function searches for a node with char     *
// parameter's value as the element to find and    *
// then deletes it.                                *
// pre: contains a char to be deleted              *
// post: deletes specified node                    *
//**************************************************

void CharList::deleteNode(char val)
{
    //used to move through the list
    ListNode *nodePtr;
    //points to the previous node
    ListNode *previousNode;

    //if the list is empty, don't do anything
    if (!head)
    {
        return;
    }
    // check the first node
    if (head->value == val)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        //start at the head of the list
        nodePtr = head;

        //skip all nodes whose values aren't equivalent to val
        while (nodePtr != nullptr && nodePtr->value != val)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        //if nodePtr isn't at the end of the list, link the previous
        //node to the node after nodePtr, then delete nodePtr
        if (nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}


//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
// pre: n/a                                        *
// post: destroyed object                          *
//**************************************************

CharList::~CharList()
{
   ListNode *nodePtr;   // To traverse the list
   ListNode *nextNode;  // To point to the next node

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr is not at the end of the list...
   while (nodePtr != nullptr)
   {
      // Save a pointer to the next node.
      nextNode = nodePtr->next;

      // Delete the current node.
      delete nodePtr;

      // Position nodePtr at the next node.
      nodePtr = nextNode;
   }
}
