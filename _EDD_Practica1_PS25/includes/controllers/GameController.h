//
// Created by Carlos Cotom on 15/02/2025.
//

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "FichasController.h"
#include "PalabrasController.h"
#include "ReportsController.h"
#include "../models/Jugador.h"
#include "../models/Tablero.h"
#include "../structs/Cola.h"
#include "../structs/LinkedList.h"
#include "../structs/Stack.h"


class GameController {

private:
    LinkedList<Jugador> *jugadores;
    Cola<Jugador*> *turnos;
    Stack<std::string> *historialPalabrasEncontradas;
    LinkedList<std::string> *palabrasIniciales;
    Tablero *tablero;
    long tiempoTotalTurno;
    int totalTurnos;

    PalabrasController *palabrasController;
    FichasController *fichasController;
    ReportsController *reportsController;

    void cargarJugadores();

    void barajarTurnos();

    int calcularPuntuacion(LinkedList<Casilla*> *casillasPalabra);

    void verificarPalabra(LinkedList<Casilla*> *casillasEvaluar, Jugador *jugadorActual);

    void reportes();

public:
    GameController();

    ~GameController();

    void jugar();

};



#endif //GAMECONTROLLER_H
