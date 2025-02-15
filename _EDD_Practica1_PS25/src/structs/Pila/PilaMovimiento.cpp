//
// Created by Carlos Cotom on 15/02/2025.
//

#include "../../../includes/structs/Pila/PilaMovimiento.h"

PilaMovimiento::PilaMovimiento() {
    this->raiz = nullptr;
}

NodoPila *PilaMovimiento::getRaiz() {
    return this->raiz;
}

void PilaMovimiento::setRaiz(NodoPila *raiz) {
    this->raiz = raiz;
}

void PilaMovimiento::push(Movimiento *movimiento) {
    if (this->raiz == nullptr) {
        this->raiz = new NodoPila(movimiento, nullptr);
    } else {
        NodoPila *aux = this->raiz;
        this->raiz = new NodoPila(movimiento, aux);
    }
}

Movimiento *PilaMovimiento::pop() {
    if (this->raiz == nullptr) return nullptr;

    Movimiento *movimiento = this->raiz->getMovimiento();
    NodoPila *aux = this->raiz;
    this->raiz = this->raiz->getSiguiente();
    delete aux;
    return movimiento;
}


