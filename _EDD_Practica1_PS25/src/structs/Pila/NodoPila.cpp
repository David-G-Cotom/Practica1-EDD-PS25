//
// Created by Carlos Cotom on 15/02/2025.
//

#include "../../../includes/structs/Pila/NodoPila.h"

NodoPila::NodoPila(Movimiento *movimiento, NodoPila *siguiente) {
    this->movimiento = movimiento;
    this->siguiente = siguiente;
}

NodoPila *NodoPila::getSiguiente() {
    return this->siguiente;
}

void NodoPila::setSiguiente(NodoPila *siguiente) {
    this->siguiente = siguiente;
}

Movimiento *NodoPila::getMovimiento() {
    return this->movimiento;
}

void NodoPila::setMovimiento(Movimiento *movimiento) {
    this->movimiento = movimiento;
}




