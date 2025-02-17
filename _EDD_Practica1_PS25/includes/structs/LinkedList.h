//
// Created by Carlos Cotom on 16/02/2025.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"



template <class T> class LinkedList {

private:
    Node<T> *raiz;

public:
    LinkedList();

    Node<T> *getRaiz();
    void setRaiz(Node<T> *raiz);

    void insertar(T value);

    void eliminar(T value);

};



#endif //LINKEDLIST_H
