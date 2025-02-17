//
// Created by Carlos Cotom on 16/02/2025.
//

#include "../../includes/structs/Stack.h"

template<class T>
Stack<T>::Stack() {
    this->raiz = nullptr;
}

template<class T>
Node<T> *Stack<T>::getRaiz() {
    return this->raiz;
}

template<class T>
void Stack<T>::setRaiz(Node<T> *raiz) {
    this->raiz = raiz;
}

template<class T>
void Stack<T>::push(T data) {
    auto *nuevoNodo = new Node<T>(data);
    nuevoNodo->setNext(this->raiz);
    this->raiz = nuevoNodo;
}

template<class T>
T Stack<T>::pop() {
    if (this->raiz == nullptr) return T();

    Node<T> *aux = this->raiz;
    T data = this->raiz->getData();
    this->raiz = this->raiz->getNext();
    delete aux;
    return data;
}

template<class T>
bool Stack<T>::isEmpty() {
    return this->raiz == nullptr;
}




