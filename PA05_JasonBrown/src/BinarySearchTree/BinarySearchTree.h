// Araam Zaremehrjardi
// Project 5
#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include <iostream>
#include "../BinaryNode/BinaryNode.h"

template <class ItemType>
class BinarySearchTree {

    private:

        BinaryNode<ItemType> * m_root;
        int getNumberOfNodesHelper(BinaryNode<ItemType> * treePointer) const; 
        int heightHelper(BinaryNode<ItemType> * treePointer) const;
        void inorderTraverseHelper(BinaryNode<ItemType> * treePointer) const;
        void postorderTraverseHelper(BinaryNode<ItemType> * treePointer) const;  
        void preorderTraverseHelper(BinaryNode<ItemType> * treePointer) const;

    protected: 

        BinaryNode<ItemType> * placeNode(BinaryNode<ItemType> * subTreePtr, BinaryNode<ItemType> * newNode);
        BinaryNode<ItemType> * removeValue(BinaryNode<ItemType> * subTreePtr, const ItemType target, bool & isSuccessful);
        BinaryNode<ItemType> * removeNode(BinaryNode<ItemType> * nodePtr);
        BinaryNode<ItemType> * removeLeftmostNode(BinaryNode<ItemType> * subTreePtr, ItemType & inorderSuccessor);
        BinaryNode<ItemType> * findNode(BinaryNode<ItemType> * treePtr, const ItemType & target) const;

    public:

        BinarySearchTree();
        BinarySearchTree(const ItemType & rootItem);  
        BinarySearchTree(const BinarySearchTree<ItemType> & tree); 
        ~BinarySearchTree();

        void preorderTraverse() const;
        void inorderTraverse() const;  
        void postorderTraverse() const;  

        bool isEmpty() const;
        int getHeight() const; 
        int getNumberOfNodes() const; 
        ItemType getRootData() const; 
        void setRootData(const ItemType & newData);
        bool add(const ItemType & newEntry);
 
        bool remove(const ItemType & target); 
        void clear(); 
        bool contains(const ItemType & anEntry) const; 

        BinarySearchTree<ItemType> & operator=(const BinarySearchTree<ItemType> & rightHandSide); 
};

#endif