// Araam Zaremehrjardi
// Project 5
#include <iostream>
#include <stdlib.h>
#include "src/BinaryNode/BinaryNode.h"
#include "src/BinaryNode/BinaryNode.cpp"
#include "src/BinarySearchTree/BinarySearchTree.h"
#include "src/BinarySearchTree/BinarySearchTree.cpp"

int main(void) {

    BinarySearchTree<int> numberSlot;

    int amountAdded = 0;
    int previousNumber = 0;

    while (amountAdded < 200){

        int newValue = rand() % 200;

        if (numberSlot.contains(newValue) == false) {
            
            numberSlot.add(newValue);
            amountAdded++;

        }
        
    }
    
    std::cout << "Height of the tree is " << numberSlot.getHeight() << ".\n" << std::endl;
    std::cout << "PREORDER: ";
    numberSlot.preorderTraverse();
    std::cout << std::endl;
    std::cout << "\n===============" << std::endl;
    std::cout << "INORDER: ";
    numberSlot.inorderTraverse();
    std::cout << "\n===============" << std::endl;
    std::cout << std::endl;
    std::cout << "POSTORDER: ";
    numberSlot.postorderTraverse();
    std::cout << "\n===============" << std::endl;
    std::cout << std::endl;

    return 0;

}