//
// Created by Carlos Cotom on 16/02/2025.
//

#ifndef COLA_H
#define COLA_H

#include "Node.h"



template <class T> class Cola {

private:
    Node<T> *inicio;
    Node<T> *fin;

public:
    Cola() {
        this->inicio = nullptr;
        this->fin = nullptr;
    }

    ~Cola() {
        Node<T> *aux = this->inicio;
        while (aux != nullptr) {    // O(n), donde n es el número de nodos en la cola
            Node<T> *siguiente = aux->getNext();
            delete aux;
            aux = siguiente;
        }
        this->inicio = nullptr;
        this->fin = nullptr;
    }

    Node<T> *getInicio() {
        return this->inicio;
    }

    void setInicio(Node<T> *inicio) {
        this->inicio = inicio;
    }

    Node<T> *getFin() {
        return this->fin;
    }

    void setFin(Node<T> *fin) {
        this->fin = fin;
    }

    void encolar(T *dato) {
        auto *nuevoNodo = new Node<T>(dato);
        if (this->fin == nullptr) {
            this->inicio = this->fin = nuevoNodo;
            return;
        }
        this->fin->setNext(nuevoNodo);
        this->fin = nuevoNodo;
    }

    void encolar2(T dato) {
        auto *nuevoNodo = new Node<T>(dato);
        if (this->fin == nullptr) {
            this->inicio = this->fin = nuevoNodo;
            return;
        }
        this->fin->setNext(nuevoNodo);
        this->fin = nuevoNodo;
    }

    T *desencolar() {
        if (this->inicio == nullptr) return T();

        Node<T> *aux = this->inicio;
        T *dato = this->inicio->getDato();
        this->inicio = this->inicio->getNext();
        if (this->inicio == nullptr) this->fin = nullptr;

        delete aux;
        return dato;
    }

    T desencolar2() {
        if (this->inicio == nullptr) return T();

        Node<T> *aux = this->inicio;
        T *dato = this->inicio->getData();
        this->inicio = this->inicio->getNext();
        if (this->inicio == nullptr) this->fin = nullptr;

        delete aux;
        return *dato;
    }

    bool isVacio() {
        return this->inicio == nullptr;
    }

};



#endif //COLA_H
