/*
   COPYRIGHT (C) 2017 William Horn (wjh27) All rights reserved.
   CS assignment 8
   Author.  Will Horn
            wjh27@zips.uakron.edu
   Version. 1.01 09.09.2017
   Purpose: is a completed binary search tree that allows you to do things such as
        find the depth of the tree and search the tree for a specific number
*/
#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include "Treenode.hpp"

// Tree class-template definition
template<typename NODETYPE> class Tree {
public:
   // insert node in Tree
   void insertNode(const NODETYPE& value) {
      insertNodeHelper(&rootPtr, value);
   }

   // begin preorder traversal of Tree
   void preOrderTraversal() const {
      preOrderHelper(rootPtr);
   }

   // begin inorder traversal of Tree
   void inOrderTraversal() const {
      inOrderHelper(rootPtr);
   }

   // begin postorder traversal of Tree
   void postOrderTraversal() const {
      postOrderHelper(rootPtr);
   }

   // get the depth of the tree
   int getDepth() const {
      int totalDepth{0};
      int currentDepth{0};

      determineDepth(rootPtr, totalDepth, currentDepth);
      return totalDepth;
   }

   // begin binary search
   TreeNode<NODETYPE>* binaryTreeSearch(int val) const {
      return binarySearchHelper(rootPtr, val);
   }

private:
   TreeNode<NODETYPE>* rootPtr{nullptr};

   // utility function called by insertNode; receives a pointer
   // to a pointer so that the function can modify pointer's value
   void insertNodeHelper(
      TreeNode<NODETYPE>** ptr, const NODETYPE& value) {
      // subtree is empty; create new TreeNode containing value
      if (*ptr == nullptr) {
         *ptr = new TreeNode<NODETYPE>(value);
      }
      else { // subtree is not empty
             // data to insert is less than data in current node
         if (value <= (*ptr)->data) {
            insertNodeHelper(&((*ptr)->leftPtr), value);
         }
         else {
            insertNodeHelper(&((*ptr)->rightPtr), value);
         }
      }
   }

   // utility function to perform preorder traversal of Tree
   void preOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         std::cout << ptr->data << ' '; // process node
         preOrderHelper(ptr->leftPtr); // traverse left subtree
         preOrderHelper(ptr->rightPtr); // traverse right subtree
      }
   }

   // utility function to perform inorder traversal of Tree
   void inOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         inOrderHelper(ptr->leftPtr); // traverse left subtree
         std::cout << ptr->data << ' '; // process node
         inOrderHelper(ptr->rightPtr); // traverse right subtree
      }
   }

   // utility function to perform postorder traversal of Tree
   void postOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         postOrderHelper(ptr->leftPtr); // traverse left subtree
         postOrderHelper(ptr->rightPtr); // traverse right subtree
         std::cout << ptr->data << ' '; // process node
      }
   }

   // calculate the depth of the tree
   /*int determineDepth(TreeNode<NODETYPE>* root, int &totalD, int &currentD) {

    if (currentD > totalD)
    {
        totalD = currentD;
    }
    currentD += 1;
    determineDepth(root->getLeftPtr(), &totalD, &currentD);
    determineDepth(root->getRightPtr(), &totalD, &currentD);

    return totalD;


   }*/

      void determineDepth(TreeNode<NODETYPE>* ptr, int &maxDepth, int& currentD) const {

          if (maxDepth < currentD)
          {
              maxDepth = currentD;
          }
        if (ptr != nullptr) {
                int newDepth = currentD + 1;
         determineDepth(ptr->leftPtr, maxDepth, newDepth); // traverse left subtree
         determineDepth(ptr->rightPtr, maxDepth, newDepth); // traverse right subtree
      }
   }

   // do a binary search on the Tree
   TreeNode<NODETYPE>* binarySearchHelper(TreeNode<NODETYPE>* root, int input) const {

    TreeNode<NODETYPE>* temp;
    temp = root;

    while (temp != nullptr)
    {
        std::cout << "Comparing " << input << " to " << temp->data << ";";
        if (input > temp->data)
        {
            std::cout << "larger, walk right\n";
            temp = temp->rightPtr;
        }
        else if (input < temp->data)
        {
            std::cout << "smaller, walk left\n";
            temp = temp->leftPtr;
        }
        else if (input == temp->data)
        {
            std::cout << "search complete\n";
            root->data = input;
            break;
        }
    }
   }
};

#endif // TREE_HPP
