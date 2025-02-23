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
    srand(time(nullptr));
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
        std::cout << "Turno de " << jugadorActual->getNombre() << " (Puntaje: " << jugadorActual->getPuntos() << ")" << std::endl;
        this->tablero->imprimirTablero();
        int opcion;
        auto inicioTiempo = std::chrono::steady_clock::now();
        do {
            std::cout << "1. Jugar Ficha\n2. Saltar Turno" << std::endl;
            Utils::verificarEntradaNumerica(opcion, "Opcion: ");
            switch (opcion) {
                case 1: {
                    Ficha *fichaUsada;
                    do {
                        std::cout << "Tus Fichas son: ";
                        jugadorActual->imprimirFichas();
                        std::cout << "Ingrese la Letra de la Ficha: ";
                        char letra;
                        std::cin.get(letra);
                        letra = toupper(letra);
                        fichaUsada = jugadorActual->usarFichas(letra);
                        if (fichaUsada == nullptr) {
                            std::cout << "Ficha con Letra " << letra << " No Encontrada!!!" << std::endl;
                        }
                    } while (fichaUsada == nullptr);
                    bool isPosicionCorrecta;
                    int x;
                    int y;
                    do {
                        isPosicionCorrecta = true;
                        Utils::verificarEntradaNumerica(x, "Ingrese la Posicion en X: ");
                        Utils::verificarEntradaNumerica(y, "Ingrese la Posicion en Y: ");
                        if (!this->tablero->isCasillaValida(x - 1, y - 1)) {
                            std::cout << "Posicion Invalida o Bloqueda!!!" << std::endl;
                            isPosicionCorrecta = false;
                        }
                    } while (!isPosicionCorrecta);
                    this->tablero->colocarFicha(x - 1, y - 1, fichaUsada);
                    this->tablero->imprimirTablero();
                    //El tablero buscara las posiciones en x & y que coinsiden en el registroanterior
                    //Devolvera una lista de las casillas tando horizontales como verticales
                    LinkedList<Casilla*> *casillasVerticales = this->tablero->buscarCasillasVerticales(x - 1, y - 1);
                    LinkedList<Casilla*> *casillasHorizontales = this->tablero->buscarCasillasHorizontales(x - 1, y - 1);
                    //extraer las palabras y sus reversas
                    //validarla en el diccionario
                    this->verificarPalabra(casillasVerticales, jugadorActual);
                    this->verificarPalabra(casillasHorizontales, jugadorActual);
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
                    jugadorActual->setMovimientos(jugadorActual->getMovimientos() + 1);
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
        if (jugadorActual->getListaFichas()->isEmpty()) {
            std::cout << "El Jugador: " << jugadorActual->getNombre() << " No Tiene Fichas!!!" << std::endl;
            break;
        }
        if (this->tablero->isTableroLleno()) {
            std::cout << "No se Pueden Formar mas Palabras!!!" << std::endl;
            break;
        }
        this->turnos->encolar2(jugadorActual);
    }
    std::cout << "FIN DE PARTIDA!!!" << std::endl;
    int opcion3;
    do {
        std::cout << "1. Ver Reportes\n2. Salir" << std::endl;
        Utils::verificarEntradaNumerica(opcion3, "Opcion: ");
        switch (opcion3) {
            case 1: {
                std::cout << "1. Historial de Plabras Jugadas" << std::endl;
                std::cout << "2. Historial de Plabras No Encontradas" << std::endl;
                std::cout << "3. Lista de Jugadores" << std::endl;
                std::cout << "4. Resumen de Tiempo Promedio por Turno" << std::endl;
                std::cout << "5. Cantidad de Movimientos por Jugador" << std::endl;
                break;
            }
            case 2: {
                std::cout << "JUEGO FINALIZADO!!!" << std::endl;
                break;
            }
            default: {
                std::cout << "Error!!! Opcion No Valida." << std::endl;
                break;
            }
        }
    } while (opcion3 != 1 && opcion3 != 2);
}

int GameController::calcularPuntuacion(LinkedList<Casilla*> *casillasPalabra) {
    int total = 0;
    Node<Casilla*> *casillaActual = casillasPalabra->getRaiz();
    while (casillaActual != nullptr) {
        total += casillaActual->getValue()->getFicha()->getValor();
        casillaActual = casillaActual->getNext();
    }
    return total;
}

void GameController::verificarPalabra(LinkedList<Casilla*> *casillasEvaluar, Jugador *jugadorActual) {
    std::string palabra;
    auto *casillasVerificadas = new LinkedList<Casilla*>();
    for (int i = 0; i < casillasEvaluar->getSize(); i++) {
        Node<Casilla*> *casillaActual = casillasEvaluar->getElement(i);
        palabra += casillaActual->getValue()->getFicha()->getLetra();
        casillasVerificadas->insertar(casillaActual->getData());
        if (this->palabrasController->isPalabraValida(palabra, this->palabrasIniciales)) {
            int puntos = this->calcularPuntuacion(casillasVerificadas);
            jugadorActual->setPuntos(jugadorActual->getPuntos() + puntos);
            this->historialPalabrasEncontradas->push(palabra);
            std::cout << "Puntos Obtenidos: " << puntos << " puntos" << std::endl;
        }
    }
}




