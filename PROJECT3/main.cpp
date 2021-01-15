// Project 3 optimized Binary Search Tree driver
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Tree.hpp"

int main() {
   srand(time(nullptr)); // randomize the random number generator

   Tree<int> intTree;
   int intVal;

   std::cout << "The values being placed in the tree are:\n";

   // generate a tree with values
   for (int i{1}; i <= 15; ++i)
   {
      intVal = rand() % 100;
      std::cout << intVal << ' ';
      intTree.insertNode(intVal);
   }

   std::cout << "\nThe depth of the tree is: " << intTree.getDepth() << '\n';

   std::cout << "\n\nEnter a value to search for: ";
   std::cin >> intVal;

   // create a pointer with the user value
   TreeNode<int>* ptr{intTree.binaryTreeSearch(intVal)};

   // a value is found
   if (ptr != nullptr) {
      std::cout << ptr->getData() << " was found\n";
   }
   else { // value not found
      std::cout << "Element was not found\n";
   }

   std::cout << std::endl;

   Tree<int> optTree;

   int depth;

   for(int i=1; i<32; i++){ //insert values 1,2,3,..., 31

   optTree.insertNode(i);

   }

   optTree.inOrderTraversal(); //you will output 1 2 3 ... 31

   std::cout << std::endl;

   std::cout << "The depth of the tree is: " << optTree.getDepth() << std::endl;

   //you will output 30 as the depth

   optTree.Optimize();

   optTree.inOrderTraversal(); //you will output 1 2 3 ... 31

   std::cout << std::endl;

   std::cout << "The depth of the tree after optimized is: " << optTree.getDepth() << std::endl;

   //the output depth will be 4
}
