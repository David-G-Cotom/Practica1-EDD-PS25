//
// Created by Carlos Cotom on 16/02/2025.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"



template <class T> class LinkedList {

private:
    Node<T> *raiz;
    int size;

public:
    LinkedList() {
        this->raiz = nullptr;
        this->size = 0;
    }

    Node<T> *getRaiz() {
        return this->raiz;
    }
    void setRaiz(Node<T> *raiz) {
        this->raiz = raiz;
    }

    int getSize() {
        return this->size;
    }
    void setSize(int size) {
        this->size = size;
    }

    Node<T> *getElement(int index) {
        if (index < 0 || index >= this->size) return nullptr;

        if (index == 0) return this->raiz;

        int contadorAux = 0;
        Node<T> *aux = this->raiz;
        while (contadorAux < index) {
            aux = aux->getNext();
            contadorAux++;
        }
        return aux;
    }

    void insertar(T *value) {
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

    void insertar(T value) {
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

    void eliminar(T *value) {
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

    Node<T> *eliminarFicha(int index) {
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

    bool isEmpty() {
        return this->raiz == nullptr;
    }

};



#endif //LINKEDLIST_H
