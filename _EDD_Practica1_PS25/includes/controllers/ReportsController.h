//
// Created by Carlos Cotom on 15/02/2025.
//

#ifndef REPORTSCONTROLLER_H
#define REPORTSCONTROLLER_H

#include "../structs/Stack.h"
#include "../models/Jugador.h"


class ReportsController {

public:
    ReportsController();

    ~ReportsController();

    void historialPalabrasJugadas(Stack<std::string> *palabrasEncontradas);

    void historialPalabrasNoEncontradas(LinkedList<std::string> *palabrasNoEncontradas);

    void jugadoresOrdenadoPuntaje(LinkedList<Jugador> *jugadores);

    void jugadoresOrdenadoNombre(LinkedList<Jugador> *jugadores);

    void tiempoPromedioTurno(long tiempoTotalTurnos, int totalTurnos);

    void movimientoPorJugador(LinkedList<Jugador> *jugadores);

};



#endif //REPORTSCONTROLLER_H
