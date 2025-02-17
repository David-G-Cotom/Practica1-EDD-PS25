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
int LinkedList<T>::getSize() {
    return this->size;
}

template<class T>
void LinkedList<T>::setSize(int size) {
    this->size = size;
}

template<class T>
Node<T> *LinkedList<T>::getElement(int index) {
    if (index < 0 || index >= this->size) return nullptr;

    if (index == 0) return this->raiz;

    int contadorAux = 0;
    Node<T> *aux = this->raiz;
    while (contadorAux < index) {
        aux = aux->getSiguiente();
        contadorAux++;
    }
    return aux;
}

template<class T>
void LinkedList<T>::insertar(T *value) {
    auto *nuevoNodo = new Node<T>(value);
    if (this->raiz == nullptr) {
        this->raiz = nuevoNodo;
        this->size++;
        return;
    }
    Node<T> *aux = this->raiz;
    while (aux->getNext() != nullptr) aux = aux->getNext();

    aux->setNext(nuevoNodo);
    this->size++;
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

template<class T>
Node<T> *LinkedList<T>::eliminarFicha(int index) {
    Node<T> *aux = this->raiz;
    Node<T> *previo = nullptr;
    for (int i = 0; i < index; i++) {
        previo = aux;
        aux = aux->getNext();
    }
    if (previo != nullptr) {
        previo->setNext(aux->getNext());
    } else {
        this->raiz = aux->getNext();
    }
    aux->setNext(nullptr);
    return aux;
}

template<class T>
bool LinkedList<T>::isEmpty() {
    return this->raiz == nullptr;
}


