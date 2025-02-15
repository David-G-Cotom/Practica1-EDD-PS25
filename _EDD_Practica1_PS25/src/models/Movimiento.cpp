//
// Created by Carlos Cotom on 15/02/2025.
//

#include "../../includes/models/Movimiento.h"

Movimiento::Movimiento() {
    this->nombreJugador = "";
    this->palabra = "";
    this->puntuacionMovimiento = 0;
    this->listaFichasUtilizadas = nullptr;
    this->contadorFichas = 0;
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

ListaFichas *Movimiento::getListaFichasUtilizadas() {
    return this->listaFichasUtilizadas;
}

void Movimiento::setListaFichasUtilizadas(ListaFichas *listaFichasUtilizadas) {
    this->listaFichasUtilizadas = listaFichasUtilizadas;
}

int Movimiento::getContadorFichas() {
    return this->contadorFichas;
}

void Movimiento::setContadorFichas(int contadorFichas) {
    this->contadorFichas = contadorFichas;
}
