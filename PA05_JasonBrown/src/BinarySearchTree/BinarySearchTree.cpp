// Araam Zaremehrjardi
// Project 5
#include <iostream>
#include "BinarySearchTree.h"

template <class ItemType>
BinaryNode<ItemType> * BinarySearchTree<ItemType>::placeNode(BinaryNode<ItemType> * subTreePtr, BinaryNode<ItemType> * newNode) {

    if (subTreePtr == NULL) {

        return newNode;

    } else if (subTreePtr -> get_data() > newNode -> get_data()){

        BinaryNode<ItemType> * temporaryPointer = placeNode(subTreePtr -> get_left(), newNode);
        subTreePtr -> set_left(temporaryPointer);

    } else {

        BinaryNode<ItemType> * temporaryPointer = placeNode(subTreePtr -> get_right(), newNode);
        subTreePtr -> set_right(temporaryPointer);

    }

    return subTreePtr;

}

template <class ItemType>
BinaryNode<ItemType> * BinarySearchTree<ItemType>::removeValue(BinaryNode<ItemType> * subTreePtr, const ItemType target, bool & isSuccessful) {

    if (subTreePtr == NULL) {

        isSuccessful = false;

    } else if (subTreePtr -> get_data() == target) {

        subTreePtr = removeNode(subTreePtr);
        isSuccessful = true;

    } else if (subTreePtr -> get_data() > target) {
    
        BinaryNode<ItemType> * temporaryPointer = removeValue(subTreePtr -> get_left(), target, isSuccessful);
        subTreePtr -> set_left(temporaryPointer);

    } else {

        BinaryNode<ItemType> * temporaryPointer = removeValue(subTreePtr -> get_right(), target, isSuccessful);
        subTreePtr -> set_right(temporaryPointer);

    }

    return subTreePtr;

}

template <class ItemType>
BinaryNode<ItemType> * BinarySearchTree<ItemType>::removeNode(BinaryNode<ItemType> * nodePtr) {

    if ((nodePtr -> get_left() == NULL) && (nodePtr -> get_right() == NULL)) {

        if (nodePtr != NULL) {
            std::cout << nodePtr -> get_data() << std::endl;
        }

        return nodePtr;

    } else if ((nodePtr -> get_left() == NULL) || (nodePtr -> get_right() == NULL)) {

        BinaryNode<ItemType> * nodeConnection;

        if (nodePtr -> get_left() != NULL) {

            nodeConnection = nodePtr -> get_left();

        } else {

            nodeConnection = nodePtr -> get_left(); 

        }

        return nodeConnection;
    } else {

        //BinaryNode<ItemType> * temporaryPointer = removeLeftmostNode(nodePtr -> get_right(), )

    }

}

template <class ItemType>
BinaryNode<ItemType> * BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType> * subTreePtr, ItemType & inorderSuccessor) {

    if (subTreePtr -> get_left() == NULL) {

        inorderSuccessor = subTreePtr -> get_data();
        return removeNode(subTreePtr);

    } else {

        BinaryNode<ItemType> * temporaryPointer = removeLeftmostNode(subTreePtr -> get_left(), inorderSuccessor);
        subTreePtr -> set_left(temporaryPointer);
        return subTreePtr;

    }

}

template <class ItemType>
BinaryNode<ItemType> * BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType> * treePtr, const ItemType & target) const {

    if (treePtr == NULL) {
        
        return NULL;

    }
    else if (treePtr -> get_data() == target) {

        return treePtr;

    } else if (treePtr -> get_data() > target) {

        return findNode(treePtr -> get_left(), target);

    }
    else {

        return findNode(treePtr -> get_right(), target);

    }

}

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(): m_root(NULL) { }

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType> & tree): m_root(tree) { }

template <class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree() { }

template <class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const {

    return m_root == NULL;

}

template <class ItemType>
int BinarySearchTree<ItemType>::getHeight() const {

    return heightHelper(m_root);

}

template <class ItemType>
int BinarySearchTree<ItemType>::heightHelper(BinaryNode<ItemType> * treePointer) const {

    if (treePointer == NULL) {

        return 0;

    } else {

        int rightDepth = heightHelper(treePointer -> get_right());
        int leftDepth = heightHelper(treePointer -> get_left());
        
        if (rightDepth > leftDepth) {
            
            return rightDepth + 1;

        }
        else if (rightDepth < leftDepth) {

            return leftDepth + 1;

        } else {

            return rightDepth + 1;

        }

    }
    
}

template <class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const {

    return getNumberOfNodesHelper(m_root);

}

template <class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType> * treePointer) const {

    int stemCount = 0;

    if (treePointer == NULL) {

        return 0;

    } else if (treePointer -> get_left() != NULL) {

        stemCount += getNumberOfNodesHelper(treePointer -> get_left());

    } else if (treePointer -> get_right() != NULL) {

        stemCount += getNumberOfNodesHelper(treePointer -> get_right());

    } else {

        return stemCount;

    }

}

template <class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const {

    return m_root -> get_data();

}

template <class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType & newData) {

    m_root -> set_data(newData);

}

template <class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType & newEntry) {

    BinaryNode<ItemType> * newNodePtr = new BinaryNode<ItemType>(newEntry);
    m_root = placeNode(m_root, newNodePtr);
    return true;

}

template <class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType & target) {

    bool isSuccessful = false;
    m_root = removeValue(m_root, target, isSuccessful);
    return isSuccessful;

}

template <class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse() const {

    preorderTraverseHelper(m_root);

}

template <class ItemType>
void BinarySearchTree<ItemType>::preorderTraverseHelper(BinaryNode<ItemType> * treePointer) const {

    if (treePointer != NULL) {
    
        std::cout << treePointer -> get_data() << " ";
        postorderTraverseHelper(treePointer -> get_left());
        postorderTraverseHelper(treePointer -> get_right());

    }
}

template <class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse() const {
    
    inorderTraverseHelper(m_root);

}

template <class ItemType>
void BinarySearchTree<ItemType>::inorderTraverseHelper(BinaryNode<ItemType> * treePointer) const {
    
    if (treePointer != NULL) {

        inorderTraverseHelper(treePointer -> get_left());
        std::cout << treePointer -> get_data() << " ";
        inorderTraverseHelper(treePointer -> get_right());

    }
    
}

template <class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse() const {
    
    postorderTraverseHelper(m_root);

}

template <class ItemType>
void BinarySearchTree<ItemType>::postorderTraverseHelper(BinaryNode<ItemType> * treePointer) const {

    if (treePointer != NULL) {

        postorderTraverseHelper(treePointer -> get_left());
        postorderTraverseHelper(treePointer -> get_right());
        std::cout << treePointer -> get_data() << " ";

    }
    
}

template <class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType & anEntry) const { 

    BinaryNode<ItemType> * treePointer = m_root;

    return findNode(treePointer, anEntry);

}
