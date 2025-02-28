//
// Created by Carlos Cotom on 16/02/2025.
//

#ifndef STACK_H
#define STACK_H

#include "Node.h"



template <class T> class Stack {

private:
    Node<T> *raiz;

public:
    Stack() {
        this->raiz = nullptr;
    }

    ~Stack() {
        Node<T> *aux = this->raiz;
        while (aux != nullptr) {
            Node<T> *siguiente = aux->getNext();
            delete aux;
            aux = siguiente;
        }
        this->raiz = nullptr;
    }

    Node<T> *getRaiz() {
        return this->raiz;
    }

    void setRaiz(Node<T> *raiz) {
        this->raiz = raiz;
    }

    void push(T data) {
        auto *nuevoNodo = new Node<T>(data);
        nuevoNodo->setNext(this->raiz);
        this->raiz = nuevoNodo;
    }

    T *pop() {
        if (this->raiz == nullptr) return nullptr;

        Node<T> *aux = this->raiz;
        T *data = this->raiz->getData();
        this->raiz = this->raiz->getNext();
        delete aux;
        return data;
    }

    bool isEmpty() {
        return this->raiz == nullptr;
    }

};



#endif //STACK_H
