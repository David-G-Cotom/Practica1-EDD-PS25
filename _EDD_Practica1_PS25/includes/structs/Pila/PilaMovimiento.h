//
// Created by Carlos Cotom on 15/02/2025.
//

#ifndef PILAMOVIMIENTO_H
#define PILAMOVIMIENTO_H

#include "NodoPila.h"



class PilaMovimiento {

private:
    NodoPila *raiz;

public:
    PilaMovimiento();

    NodoPila *getRaiz();
    void setRaiz(NodoPila *raiz);

    void push(Movimiento *movimiento);
    Movimiento *pop();

};



#endif //PILAMOVIMIENTO_H
