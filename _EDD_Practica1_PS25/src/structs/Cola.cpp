//
// Created by Carlos Cotom on 16/02/2025.
//

#include "../../includes/structs/Cola.h"

template<class T>
Cola<T>::Cola() {
    this->inicio = nullptr;
    this->fin = nullptr;
}

template<class T>
Node<T> *Cola<T>::getInicio() {
    return this->inicio;
}

template<class T>
void Cola<T>::setInicio(Node<T> *inicio) {
    this->inicio = inicio;
}

template<class T>
Node<T> *Cola<T>::getFin() {
    return this->fin;
}

template<class T>
void Cola<T>::setFin(Node<T> *fin) {
    this->fin = fin;
}

template<class T>
void Cola<T>::encolar(T dato) {
    auto *nuevoNodo = new Node<T>(dato);
    if (this->fin == nullptr) {
        this->inicio = this->fin = nuevoNodo;
        return;
    }
    this->fin->setNext(nuevoNodo);
    this->fin = nuevoNodo;
}

template<class T>
T Cola<T>::desencolar() {
    if (this->inicio == nullptr) return T();

    Node<T> *aux = this->inicio;
    T dato = this->inicio->getDato();
    this->inicio = this->inicio->getNext();
    if (this->inicio == nullptr) this->fin = nullptr;

    delete aux;
    return dato;
}

template<class T>
bool Cola<T>::isVacio() {
    return this->inicio == nullptr;
}




