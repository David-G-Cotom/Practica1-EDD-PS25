//
// Created by Carlos Cotom on 14/02/2025.
//

#include "../../../includes/structs/ListaEnlazada/ListaFichas.h"

ListaFichas::ListaFichas() {
    this->inicio = nullptr;
    this->fin = nullptr;
    this->size = 0;
}

NodoLista *ListaFichas::getInicio() {
    return this->inicio;
}

void ListaFichas::setInicio(NodoLista *inicio) {
    this->inicio = inicio;
}

NodoLista *ListaFichas::getFin() {
    return this->fin;
}

void ListaFichas::setFin(NodoLista *fin) {
    this->fin = fin;
}

int ListaFichas::getSize() {
    return this->size;
}

void ListaFichas::setSize(int size) {
    this->size = size;
}

NodoLista *ListaFichas::getElement(int index) {
    if (index < 0 || index >= this->size) return nullptr;

    if (index == 0) return this->inicio;

    if (index == this->size - 1) return this->fin;

    int contadorAux = 0;
    NodoLista *aux = this->inicio;
    while (contadorAux < index) {
        aux = aux->getSiguiente();
        contadorAux++;
    }
    return aux;
}


void ListaFichas::insertarFicha(Ficha *ficha) {
    auto *nodoNuevo = new NodoLista(ficha);
    if (!this->isEmpty()) {
        this->fin->setSiguiente(nodoNuevo);
        this->fin = nodoNuevo;
    } else {
        this->inicio = this->fin = nodoNuevo;
    }
    this->size++;
}

void ListaFichas::eliminarFicha() {

}

void ListaFichas::recorrerLista() {

}

bool ListaFichas::isEmpty() {
    return this->inicio == nullptr && this->size == 0;
}




