//
// Created by Carlos Cotom on 16/02/2025.
//

#include "../../includes/structs/LinkedList.h"

template<class T>
LinkedList<T>::LinkedList() {
    this->raiz = nullptr;
}

template<class T>
Node<T> *LinkedList<T>::getRaiz() {
    return this->raiz;
}

template<class T>
void LinkedList<T>::setRaiz(Node<T> *raiz) {
    this->raiz = raiz;
}

template<class T>
void LinkedList<T>::insertar(T value) {
    auto *nuevoNodo = new Node<T>(value);
    if (this->raiz == nullptr) {
        this->raiz = nuevoNodo;
        return;
    }
    Node<T> *aux = this->raiz;
    while (aux->getNext() != nullptr) aux = aux->getNext();

    aux->setNext(nuevoNodo);
}

template<class T>
void LinkedList<T>::eliminar(T value) {
    Node<T> *aux = this->raiz;
    Node<T> *previo = nullptr;
    while (aux != nullptr && aux->getData() != value) {
        previo = aux;
        aux = aux->getNext();
    }
    if (aux == nullptr) return;

    if (previo != nullptr) {
        previo->setNext(aux->getNext());
    } else {
        this->raiz = aux->getNext();
    }
    delete aux;
}


