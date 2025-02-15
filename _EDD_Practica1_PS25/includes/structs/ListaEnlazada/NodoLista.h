//
// Created by Carlos Cotom on 14/02/2025.
//

#ifndef NODOLISTA_H
#define NODOLISTA_H

#include "../../models/Ficha.h"



class NodoLista {

private:
    NodoLista *siguiente;
    Ficha *ficha;

public:
    NodoLista();
    NodoLista(Ficha *ficha);

    NodoLista *getSiguiente();
    void setSiguiente(NodoLista *siguiente);

    Ficha *getFicha();
    void setFicha(Ficha *ficha);

};



#endif //NODOLISTA_H
