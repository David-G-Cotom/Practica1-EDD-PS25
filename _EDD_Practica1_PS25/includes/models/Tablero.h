//
// Created by Carlos Cotom on 15/02/2025.
//

#ifndef TABLERO_H
#define TABLERO_H



class Tablero {

private:
    static const int SIZE = 15;    //El tablero sera de 15*15
    const int CASILLAS_BLOQUEADAS = 10;
    const char SIMBOLO_CASILLA_LIBRE = ' ';
    const char SIMBOLO_CASILLA_BLOQUEADA = '-';

    char tablero[SIZE][SIZE];

    void inicializarTablero();
    void bloquearCasillas();

public:
    Tablero();

    void imprimirTablero();

    bool isCasillaValida(int x, int y);

};



#endif //TABLERO_H
