//
// Created by Carlos Cotom on 14/02/2025.
//

#include "../../../includes/structs/ListaEnlazada/NodoLista.h"

NodoLista::NodoLista() {
    this->siguiente = nullptr;
    this->ficha = nullptr;
}

NodoLista::NodoLista(Ficha *ficha) {
    this->siguiente = nullptr;
    this->ficha = ficha;
}

NodoLista *NodoLista::getSiguiente() {
    return this->siguiente;
}

void NodoLista::setSiguiente(NodoLista *siguiente) {
    this->siguiente = siguiente;
}

Ficha *NodoLista::getFicha() {
    return this->ficha;
}

void NodoLista::setFicha(Ficha *ficha) {
    this->ficha = ficha;
}




