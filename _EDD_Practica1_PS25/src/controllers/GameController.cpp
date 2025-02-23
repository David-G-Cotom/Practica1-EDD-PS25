//
// Created by Carlos Cotom on 15/02/2025.
//

#include "../../includes/controllers/GameController.h"
#include "../../includes/Utils.h"

#include <chrono>
#include <iostream>
#include <ostream>
#include <filesystem>

GameController::GameController() {
    this->jugadores = new LinkedList<Jugador>;
    this->turnos = new Cola<Jugador*>;
    this->historialPalabrasEncontradas = new Stack<std::string>;
    this->palabrasNoEncontradas = new LinkedList<std::string>;
    this->palabrasIniciales = new LinkedList<std::string>;
    this->tablero = new Tablero();
    this->tiempoTotalTurno = 0;
    this->totalTurnos = 0;
    this->palabrasController = new PalabrasController();
    this->fichasController = new FichasController();
}

void GameController::cargarJugadores() {
    int cantidadJugadores;
    Utils::verificarEntradaNumerica(cantidadJugadores, "Ingrese el Numero de Jugadores (Minimo 2. Maximo 5): ");
    while (cantidadJugadores < 2 || cantidadJugadores > 5) {
        Utils::verificarEntradaNumerica(cantidadJugadores, "Se Requiere al Menos 2 Jugadores y No Mas de 5 Jugadores. Ingrese de Nuevo: ");
    }
    for (int i = 0; i < cantidadJugadores; i++) {
        std::string nombre;
        std::cout << "Ingrese el Nombre del Jugador " << i + 1 << ": ";
        std::getline(std::cin, nombre);
        this->jugadores->insertar(new Jugador(nombre));
        std::cout << "Jugador Registrado!!!" << std::endl;
    }
}

void GameController::barajarTurnos() {
    srand(time(NULL));
    int cantidadIntercambios = this->jugadores->getSize() * 2;
    LinkedList<Jugador> *jugadoresAux = this->jugadores;
    for (int i = 0; i < cantidadIntercambios; i++) {
        int indexRandom = rand() % this->jugadores->getSize();
        Node<Jugador> *aux = jugadoresAux->getElement(indexRandom);
        Jugador *jugadorAux = aux->getData();
        if (aux->getNext() == nullptr) {
            aux->setData(jugadoresAux->getRaiz()->getData());
            jugadoresAux->getRaiz()->setData(jugadorAux);
            continue;
        }
        aux->setData(aux->getNext()->getData());
        aux->getNext()->setData(jugadorAux);
    }
    Node<Jugador> *aux = jugadoresAux->getRaiz();
    while (aux != nullptr) {
        this->turnos->encolar2(aux->getData());
        aux = aux->getNext();
    }
}

void GameController::jugar() {
    std::string nombreArchivo;
    std::cout << "Ingrese el Nombre del Archivo de palabras: ";
    getline(std::cin, nombreArchivo);
    this->palabrasIniciales = this->palabrasController->cargarPalabras(nombreArchivo);
    /*for (int i = 0; i < this->palabrasIniciales->getSize(); ++i) {
        std::cout << this->palabrasIniciales->getElement(i)->getValue() << std::endl;
    }*/
    this->palabrasController->ordenarPalabras(this->palabrasIniciales);
    /*for (int i = 0; i < this->palabrasIniciales->getSize(); ++i) {
        std::cout << this->palabrasIniciales->getElement(i)->getValue() << std::endl;
    }*/
    this->cargarJugadores();
    LinkedList<Ficha> *fichasPartida = this->fichasController->crearFichasIniciales(this->palabrasIniciales);
    /*for (int i = 0; i < fichasPartida->getSize(); ++i) {
        std::cout << fichasPartida->getElement(i)->getData()->getLetra() << std::endl;
        std::cout << fichasPartida->getElement(i)->getData()->getValor() << std::endl;
        std::cout << std::endl;
    }*/
    this->fichasController->distribuirFichas(fichasPartida, this->jugadores);
    /*for (int i = 0; i < this->jugadores->getSize(); ++i) {
        std::cout << "Fichas jugador " << i + 1 << ": " << std::endl;
        Jugador *aux = this->jugadores->getElement(i)->getData();
        std::cout << "Jugador tiene " << aux->getListaFichas()->getSize() << " Fichas" << std::endl;
        for (int j = 0; j < aux->getListaFichas()->getSize(); ++j) {
            std::cout << aux->getListaFichas()->getElement(j)->getData()->getLetra() << std::endl;
            std::cout << aux->getListaFichas()->getElement(j)->getData()->getValor() << std::endl;
        }
        std::cout << std::endl;
    }*/
    this->barajarTurnos();
    std::cout << "\nINICIANDO PARTIDA!!!" << std::endl;
    while (!this->turnos->isVacio()) {
        Jugador *jugadorActual = this->turnos->desencolar2();
        if (jugadorActual->getListaFichas()->isEmpty()) {
            std::cout << jugadorActual->getNombre() << " no Tiene Fichas, se Omite su Turno!!!" << std::endl;
            continue;
        }
        std::cout << "Turno de " << jugadorActual->getNombre() << " (Puntaje: " << jugadorActual->getPuntos() << ")" << std::endl;
        this->tablero->imprimirTablero();
        int opcion;
        auto inicioTiempo = std::chrono::steady_clock::now();
        do {
            std::cout << "1. Jugar Ficha\n2. Saltar Turno" << std::endl;
            Utils::verificarEntradaNumerica(opcion, "Opcion: ");
            switch (opcion) {
                case 1: {
                    std::cout << "Tus Fichas son: ";
                    jugadorActual->imprimirFichas();
                    std::cout << "Ingrese la Letra de la Ficha: ";
                    char letra;
                    std::cin >> letra;
                    letra = toupper(letra);
                    /*
                    if (!jugadorActual->puedeFormarPalabra(palabra)) {
                        std::cout << "No tiene las Fichas Necesarias!!!" << std::endl;
                        this->turnos->encolar(jugadorActual);
                        continue;
                    }
                    if (!this->palabrasController->isPalabraValida(palabra, this->palabrasIniciales)) {
                        std::cout << "Palabra No Valida!!!" << std::endl;
                        this->turnos->encolar(jugadorActual);
                        continue;
                    }
                    */
                    bool isPosicionCorrecta;
                    int x;
                    int y;
                    do {
                        isPosicionCorrecta = true;
                        std::cout << "Ingrese la Posicion en X: ";
                        std::cin >> x;
                        std::cout << "Ingrese la Posicion en Y: ";
                        std::cin >> y;
                        if (!this->tablero->isCasillaValida(x, y)) {
                            std::cout << "Posicion Invalida o Bloqueda!!!" << std::endl;
                            std::cout << "Intente de Nuevo" << std::endl;
                            isPosicionCorrecta = false;
                        }
                    } while (!isPosicionCorrecta);
                    //REGISTRAR LA POSICION DE LA LETRA
                    //QUITARLE LA LETRA AL JUGADOR
                    this->tablero->colocarLetra(x, y, letra);

                    //HACER LO PLATICADO EN LA U
                    //en el tablero buscar las posiciones en x o y que coinsiden en el registroanterior
                    //extraer la palabra
                    //validarla en el diccionario
                    /*
                    int puntos = this->calcularPuntuacion(palabra);
                    jugadorActual->setPuntos(jugadorActual->getPuntos() + puntos);
                    jugadorActual->usarFichas(palabra);
                    this->historialPalabrasEncontradas->push(palabra);
                    std::cout << "Palabra Colocada!!! " << puntos << " puntos" << std::endl;
                    */
                    this->tablero->imprimirTablero();
                    int opcion2;
                    do {
                        std::cout << "¿Deshacer Ultima Jugada?\n1. SI\n2. NO" << std::endl;
                        Utils::verificarEntradaNumerica(opcion2, "Opcion: ");
                        switch (opcion2) {
                            case 1: {
                                if (!this->historialPalabrasEncontradas->isEmpty()) {
                                    std::string *ultimaPalabra = this->historialPalabrasEncontradas->pop();
                                    //FALTA HACER ALGO AQUI
                                    std::cout << "Ultima Jugada Desecha!!!" << std::endl;
                                }
                                break;
                            }
                            case 2: {
                                std::cout << "Operacion Cancelada!!!" << std::endl;
                                break;
                            }
                            default: {
                                std::cout << "Error!!! Opcion No Valida." << std::endl;
                                break;
                            }
                        }
                    } while (opcion != 1 && opcion != 2);
                    break;
                }
                case 2: {
                    std::cout << "Turno Saltado!!!" << std::endl;
                    break;
                }
                default: {
                    std::cout << "Error!!! Opcion No Valida." << std::endl;
                    break;
                }
            }
        } while (opcion != 1 && opcion != 2);
        auto finTiempo = std::chrono::steady_clock::now();
        auto tiempoTurno = std::chrono::duration_cast<std::chrono::milliseconds>(finTiempo - inicioTiempo).count();
        this->tiempoTotalTurno += tiempoTurno;
        this->totalTurnos++;
        if (!jugadorActual->getListaFichas()->isEmpty()) {
            this->turnos->encolar(&jugadorActual);
        }
    }
}

int GameController::calcularPuntuacion(std::string &palabra) {
    int total = 0;
    for (char letra: palabra) {
        for (int i = 0; i < this->jugadores->getSize(); ++i) {
            Jugador *jugador = this->jugadores->getElement(i)->getData();
            for (int j = 0; j < jugador->getListaFichas()->getSize(); ++j) {
                Ficha *ficha = jugador->getListaFichas()->getElement(j)->getData();
                if (ficha->getLetra() == letra) {
                    total += ficha->getValor();
                    break;
                }
            }
        }
    }
    return total;
}




