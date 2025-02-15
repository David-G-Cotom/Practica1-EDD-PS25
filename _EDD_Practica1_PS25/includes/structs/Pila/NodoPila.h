//
// Created by Carlos Cotom on 15/02/2025.
//

#ifndef NODOPILA_H
#define NODOPILA_H

#include "../../models/Movimiento.h"



class NodoPila {

private:
    NodoPila *siguiente;
    Movimiento *movimiento;

public:
    NodoPila(Movimiento *movimiento, NodoPila *siguiente);

    NodoPila *getSiguiente();
    void setSiguiente(NodoPila *siguiente);

    Movimiento *getMovimiento();
    void setMovimiento(Movimiento *movimiento);

};



#endif //NODOPILA_H
