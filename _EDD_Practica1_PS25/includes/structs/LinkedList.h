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
    LinkedList();

    Node<T> *getRaiz();
    void setRaiz(Node<T> *raiz);

    int getSize();
    void setSize(int size);

    Node<T> *getElement(int index);

    void insertar(T *value);

    void eliminar(T value);
    Node<T> *eliminarFicha(int index);

    bool isEmpty();

};



#endif //LINKEDLIST_H
