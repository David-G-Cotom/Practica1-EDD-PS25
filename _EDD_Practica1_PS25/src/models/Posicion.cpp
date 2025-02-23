//
// Created by Carlos Cotom on 17/02/2025.
//

#include "../../includes/models/Posicion.h"

Posicion::Posicion(int x, int y) {
    this->x = x;
    this->y = y;
}

int Posicion::getX() {
    return this->x;
}

void Posicion::setX(int x) {
    this->x = x;
}

int Posicion::getY() {
    return this->y;
}

void Posicion::setY(int y) {
    this->y = y;
}

