//
// Created by Carlos Cotom on 15/02/2025.
//

#include "../../includes/controllers/GameController.h"

#include <chrono>
#include <iostream>
#include <ostream>

GameController::GameController() {
    this->jugadores = new LinkedList<Jugador>;
    this->turnos = new Cola<Jugador*>;
    this->historialPalabrasEncontradas = new Stack<std::string>;
    this->palabrasNoEncontradas = new LinkedList<std::string>;
    this->palabrasIniciales = new LinkedList<std::string>;
    this->tablero = new Tablero();
    this->tiempoTotalTurno = 0;
    this->totalTurnos = 0;
}

void GameController::cargarJugadores() {
    std::cout << "Ingrese el Numero de Jugadores (Minimo 2): ";
    int cantidadJugadores = 0;
    std::cin >> cantidadJugadores;
    while (cantidadJugadores < 2) {
        std::cout << "Se Requiere al Menos 2 Jugadores. Ingrese de Nuevo: ";
        std::cin >> cantidadJugadores;
    }
    for (int i = 0; i < cantidadJugadores; i++) {
        std::cout << "Ingrese el Nombre del Jugador " << i + 1 << ": ";
        std::string nombre;
        std::cin >> nombre;
        this->jugadores->insertar(new Jugador(nombre));
    }
}

void GameController::barajarTurnos() {
    int cantidadIntercambios = this->jugadores->getSize() * 2;
    LinkedList<Jugador> *jugadoresAux = this->jugadores;
    for (int i = 0; i < cantidadIntercambios; i++) {
        int indexRandom = rand() % this->jugadores->getSize();
        Jugador *aux = jugadoresAux->getElement(indexRandom)->getData();
        Node<Jugador> *siguiente = jugadoresAux->getElement(indexRandom + 1);
        if (siguiente == nullptr) continue;
        jugadoresAux->getElement(indexRandom)->setData(siguiente->getData());
        siguiente->setData(aux);
    }
    Node<Jugador> *aux = jugadoresAux->getRaiz();
    while (aux != nullptr) {
        this->turnos->encolar(aux->getData());
        aux = aux->getNext();
    }
}

void GameController::jugar() {
    while (!this->turnos->isVacio()) {
        Jugador *jugadorActual = this->turnos->desencolar();
        if (jugadorActual->getListaFichas()->isEmpty()) {
            std::cout << jugadorActual->getNombre() << " no Tiene Fichas, se Omite su Turno!!!" << std::endl;
            continue;
        }
        std::cout << "\nTurno de " << jugadorActual->getNombre() << " (Puntaje: " << jugadorActual->getPuntos() << ")" << std::endl;
        this->tablero->imprimirTablero();
        std::cout << "Tus Fichas son: ";
        jugadorActual->imprimirFichas();
        std::string opcion;
        auto inicioTiempo = std::chrono::steady_clock::now();
        do {
            std::cout << "1. Jugar Ficha\n2. Deshacer ultima Jugada" << std::endl;
            std::cout << "Opcion: ";
            std::cin >> opcion;
            switch (opcion) {
                case "1": {
                    std::cout << "Ingrese la Letra de la Ficha: ";
                    char letra;
                    std::cin >> letra;
                    letra = toupper(letra);
                    std::cout << "Ingrese la Posicion en X: ";
                    int x;
                    std::cin >> x;
                    std::cout << "Ingrese la Posicion en Y: ";
                    int y;
                    std::cin >> y;
                    if (!this->tablero->isCasillaValida(x, y)) {
                        std::cout << "Posicion Invalida o Bloqueda!!!";
                        continue;
                    }
                    //Seguir con la Logica del Juego
                    break;
                }
                case "2": {
                    //Seguir con la Logica del Juego
                    break;
                }
                default: {
                    std::cout << "Error!!! Opcion No Valida." << std::endl;
                    break;
                }
            }
        } while (opcion != "1" && opcion != "2");
        auto finTiempo = std::chrono::steady_clock::now();
        auto tiempoTurno = std::chrono::duration_cast<std::chrono::milliseconds>(finTiempo - inicioTiempo).count();
        this->tiempoTotalTurno += tiempoTurno;
        this->totalTurnos++;
        if (!jugadorActual->getListaFichas()->isEmpty()) {
            this->turnos->encolar(jugadorActual);
        }
    }
}




