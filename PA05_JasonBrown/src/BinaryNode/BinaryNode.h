// Araam Zaremehrjardi
// Project 5
#ifndef BINARY_NODE_H_
#define BINARY_NODE_H_

#include <iostream>

template <class ItemType> class BinaryNode;
template <class ItemType> class BinarySearchTree;

template <class ItemType>
class BinaryNode {

    private:

        ItemType m_data;
        BinaryNode<ItemType> * m_left;
        BinaryNode<ItemType> * m_right;

    public:

        BinaryNode();
        BinaryNode(const ItemType & data, BinaryNode<ItemType> * left = NULL, BinaryNode<ItemType> * right = NULL);
        BinaryNode(const BinaryNode<ItemType> & other);

        ItemType & get_data();
        const ItemType & get_data() const;
        BinaryNode<ItemType> * get_right();
        BinaryNode<ItemType> * get_left();

        void set_data(const ItemType & data);
        void set_right(BinaryNode<ItemType> * data);
        void set_left(BinaryNode<ItemType> * data);



};

#endif