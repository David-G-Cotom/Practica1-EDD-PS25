//
// Created by Carlos Cotom on 14/02/2025.
//

#ifndef LISTAFICHAS_H
#define LISTAFICHAS_H

#include "NodoLista.h"
#include "../../models/Ficha.h"



class ListaFichas {

private:
    NodoLista *inicio;
    NodoLista *fin;
    int size;

public:
    ListaFichas();

    NodoLista *getInicio();
    void setInicio(NodoLista *inicio);

    NodoLista *getFin();
    void setFin(NodoLista *fin);

    int getSize();
    void setSize(int size);

    NodoLista *getElement(int index);

    void insertarFicha(Ficha *ficha);
    void eliminarFicha();

    void recorrerLista();

    bool isEmpty();

};



#endif //LISTAFICHAS_H
