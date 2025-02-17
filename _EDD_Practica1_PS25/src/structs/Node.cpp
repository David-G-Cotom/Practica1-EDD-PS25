//
// Created by Carlos Cotom on 16/02/2025.
//

#include "../../includes/structs/Node.h"

template<class T>
Node<T>::Node(T *value) {
    this->data = value;
    this->next = nullptr;
}

template<class T>
T *Node<T>::getData() {
    return this->data;
}

template<class T>
void Node<T>::setData(T *value) {
    this->data = value;
}

template<class T>
Node<T> *Node<T>::getNext() {
    return this->next;
}

template<class T>
void Node<T>::setNext(Node *next) {
    this->next = next;
}




