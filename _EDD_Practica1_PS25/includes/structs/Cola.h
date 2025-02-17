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
    Cola();

    Node<T> *getInicio();
    void setInicio(Node<T> *inicio);

    Node<T> *getFin();
    void setFin(Node<T> *fin);

    void encolar(T dato);

    T desencolar();

    bool isVacio();

};



#endif //COLA_H
