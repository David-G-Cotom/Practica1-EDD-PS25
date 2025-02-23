//
// Created by Carlos Cotom on 15/02/2025.
//

#include "../../includes/models/Jugador.h"

#include <iostream>

Jugador::Jugador(std::string nombre) {
    this->nombre = nombre;
    this->puntos = 0;
    this->movimientos = 0;
    this->listaFichas = new LinkedList<Ficha>;
}

std::string Jugador::getNombre() {
    return this->nombre;
}

void Jugador::setNombre(std::string nombre) {
    this->nombre = nombre;
}

int Jugador::getPuntos() {
    return this->puntos;
}

void Jugador::setPuntos(int puntos) {
    this->puntos = puntos;
}

int Jugador::getMovimientos() {
    return this->movimientos;
}

void Jugador::setMovimientos(int movimientos) {
    this->movimientos = movimientos;
}

LinkedList<Ficha>* Jugador::getListaFichas() {
    return this->listaFichas;
}

void Jugador::setListaFichas(LinkedList<Ficha> *listaFichas) {
    this->listaFichas = listaFichas;
}

// Inserta una ficha en la lista enlazada ordenada de mayor a menor valor.
// Complejidad: O(n log n)
void Jugador::insertarFichaOrdenada(Node<Ficha> *nodoNuevo) {
    if (this->listaFichas->isEmpty() || nodoNuevo->getData()->getValor() > this->listaFichas->getRaiz()->getData()->getValor()) {
        nodoNuevo->setNext(this->listaFichas->getRaiz());
        this->listaFichas->setRaiz(nodoNuevo);
    } else {
        Node<Ficha> *aux = this->listaFichas->getRaiz();
        while (aux->getNext() != nullptr
            && aux->getNext()->getData()->getValor() >= nodoNuevo->getData()->getValor()) {
            aux = aux->getNext();
            }
        nodoNuevo->setNext(aux->getNext());
        aux->setNext(nodoNuevo);
    }
    this->listaFichas->setSize(this->listaFichas->getSize() + 1);
}

void Jugador::imprimirFichas() {
    Node<Ficha> *aux = this->listaFichas->getRaiz();
    while (aux != nullptr) {
        std::cout << aux->getData()->getLetra() << "(" << aux->getData()->getValor() << ") - ";
        aux = aux->getNext();
    }
    std::cout << std::endl;
}

/*bool Jugador::puedeFormarPalabra(std::string &palabra) {
    LinkedList<char> aux;
    for (char letra: palabra) {
        bool encontrado = false;
        for (int i = 0; i < this->listaFichas->getSize(); ++i) {
            if (this->listaFichas->getElement(i)->getData()->getLetra() == letra) {
                aux.insertar(&letra);
                encontrado = true;
                break;
            }
        }
        if (!encontrado) return false;
    }
    return true;
}*/

void Jugador::usarFichas(std::string &palabra) {
    for (char letra: palabra) {
        Node<Ficha> *aux = this->listaFichas->getRaiz();
        while (aux != nullptr) {
            if (aux->getData()->getLetra() == letra) {
                this->listaFichas->eliminar(aux->getData());
                break;
            }
            aux = aux->getNext();
        }
    }
}




