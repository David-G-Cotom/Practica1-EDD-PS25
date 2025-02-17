//
// Created by Carlos Cotom on 14/02/2025.
//

#include "../../../includes/structs/ListaEnlazada/ListaFichas.h"

#include <iostream>
#include <ostream>

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

// Metodo de Insercion Tradicional/Comun
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

// Inserta una ficha en la lista enlazada ordenada de mayor a menor valor.
// Complejidad: O(n log n)
void ListaFichas::insertarFichaOrdenada(NodoLista *nodoNuevo) {
    if (this->isEmpty() || nodoNuevo->getFicha()->getValor() > this->inicio->getFicha()->getValor()) {
        nodoNuevo->setSiguiente(this->inicio);
        this->inicio = nodoNuevo;
    } else {
        NodoLista *aux = this->inicio;
        while (aux->getSiguiente() != nullptr
            && aux->getSiguiente()->getFicha()->getValor() >= nodoNuevo->getFicha()->getValor()) {
            aux = aux->getSiguiente();
        }
        nodoNuevo->setSiguiente(aux->getSiguiente());
        aux->setSiguiente(nodoNuevo);
    }
}

// Elimina (si existe) la primera ficha que tenga la letra solicitada
// Retorna el puntero a la ficha eliminada o nullptr si no se encontró
NodoLista *ListaFichas::eliminarFicha(char letra) {
    NodoLista *aux = this->inicio;
    NodoLista *previo = nullptr;
    while (aux != nullptr) {
        if (toupper(aux->getFicha()->getLetra()) == toupper(letra)) {
            if (previo == nullptr) {
                this->inicio = aux->getSiguiente();
            } else {
                previo->setSiguiente(aux->getSiguiente());
            }
            aux->setSiguiente(nullptr);
            return aux;
        }
        previo = aux;
        aux = aux->getSiguiente();
    }
    return nullptr;
}

NodoLista *ListaFichas::eliminarFicha(int index) {
    NodoLista *aux = this->inicio;
    NodoLista *previo = nullptr;
    for (int i = 0; i < index; i++) {
        previo = aux;
        aux = aux->getSiguiente();
    }
    if (previo != nullptr) {
        previo->setSiguiente(aux->getSiguiente());
    } else {
        this->inicio = aux->getSiguiente();
    }
    aux->setSiguiente(nullptr);
    return aux;
}

void ListaFichas::recorrerLista() {
    NodoLista *aux = this->inicio;
    while (aux != nullptr) {
        std::cout << aux->getFicha()->getLetra() << "(" << aux->getFicha()->getValor() << ") - ";
        aux = aux->getSiguiente();
    }
    std::cout << std::endl;
}

bool ListaFichas::isEmpty() {
    return this->inicio == nullptr && this->size == 0;
}




