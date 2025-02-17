//
// Created by Carlos Cotom on 15/02/2025.
//

#include "../../includes/models/Jugador.h"

Jugador::Jugador() {
    this->nombre = "";
    this->puntos = 0;
    this->movimientos = 0;
    this->listaFichas = nullptr;
}

Jugador::Jugador(std::string nombre) {
    this->nombre = nombre;
    this->puntos = 0;
    this->movimientos = 0;
    this->listaFichas = new ListaFichas();
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

ListaFichas* Jugador::getListaFichas() {
    return this->listaFichas;
}

void Jugador::setListaFichas(ListaFichas *listaFichas) {
    this->listaFichas = listaFichas;
}


