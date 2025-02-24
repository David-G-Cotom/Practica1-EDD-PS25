//
// Created by Carlos Cotom on 23/02/2025.
//

#include "../../includes/models/Casilla.h"

Casilla::Casilla() {
    this->ficha = nullptr;
    this->isHabilitada = true;
}

Casilla::Casilla(Ficha *ficha, bool isHabilitada) {
    this->ficha = ficha;
    this->isHabilitada = isHabilitada;
}

Ficha *Casilla::getFicha() {
    return this->ficha;
}

void Casilla::setFicha(Ficha *ficha) {
    this->ficha = ficha;
}

bool Casilla::getIsHabilitada() {
    return this->isHabilitada;
}

void Casilla::setIsHabilitada(bool isHabilitada) {
    this->isHabilitada = isHabilitada;
}


