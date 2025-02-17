//
// Created by Carlos Cotom on 15/02/2025.
//

#include "../../includes/models/Movimiento.h"

Movimiento::Movimiento(std::string nombreJugador, std::string palabra, int puntuacionMovimiento, Ficha *fichaJugada, int contadorFichas) {
    this->nombreJugador = nombreJugador;
    this->palabra = palabra;
    this->puntuacionMovimiento = puntuacionMovimiento;
    this->listaFichasUtilizadas = nullptr;
    this->contadorFichas = contadorFichas;
}

std::string Movimiento::getNombreJugador() {
    return this->nombreJugador;
}

void Movimiento::setNombreJugador(std::string nombreJugador) {
    this->nombreJugador = nombreJugador;
}

std::string Movimiento::getPalabra() {
    return this->palabra;
}

void Movimiento::setPalabra(std::string palabra) {
    this->palabra = palabra;
}

int Movimiento::getPuntuacionMovimiento() {
    return this->puntuacionMovimiento;
}

void Movimiento::setPuntuacionMovimiento(int puntuacionMovimiento) {
    this->puntuacionMovimiento = puntuacionMovimiento;
}

LinkedList<Ficha> *Movimiento::getListaFichasUtilizadas() {
    return this->listaFichasUtilizadas;
}

void Movimiento::setListaFichasUtilizadas(LinkedList<Ficha> *listaFichasUtilizadas) {
    this->listaFichasUtilizadas = listaFichasUtilizadas;
}

int Movimiento::getContadorFichas() {
    return this->contadorFichas;
}

void Movimiento::setContadorFichas(int contadorFichas) {
    this->contadorFichas = contadorFichas;
}
