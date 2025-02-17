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
    Stack();

    Node<T> *getRaiz();
    void setRaiz(Node<T> *raiz);

    void push(T data);

    T pop();

    bool isEmpty();

};



#endif //STACK_H
