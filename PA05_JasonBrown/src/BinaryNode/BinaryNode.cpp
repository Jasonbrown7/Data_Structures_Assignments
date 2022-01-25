// Araam Zaremehrjardi
// Project 5
#include <iostream>
#include "BinaryNode.h"

template <class ItemType>
BinaryNode<ItemType>::BinaryNode(): m_left(NULL), m_right(NULL) { }

template <class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType & data, BinaryNode<ItemType> * left, BinaryNode<ItemType> * right): m_data(data), m_left(left), m_right(right) { }

template <class ItemType>
BinaryNode<ItemType>::BinaryNode(const BinaryNode<ItemType> & other): m_data(other.m_data), m_left(other.m_left), m_right(other.m_right) { }

template <class ItemType>
ItemType & BinaryNode<ItemType>::get_data() {

    return m_data;

}

template <class ItemType>
const ItemType & BinaryNode<ItemType>::get_data() const {

    return m_data;

}

template <class ItemType>
BinaryNode<ItemType> * BinaryNode<ItemType>::get_right() {

    return m_right;

}

template <class ItemType>
BinaryNode<ItemType> * BinaryNode<ItemType>::get_left() {

    return m_left;

}

template <class ItemType>
void BinaryNode<ItemType>::set_data(const ItemType & data) {

    m_data = data;

}

template <class ItemType>
void BinaryNode<ItemType>::set_right(BinaryNode<ItemType> * data) {

    m_right = data;

}

template <class ItemType>
void BinaryNode<ItemType>::set_left(BinaryNode<ItemType> * data) {

    m_left = data;

}