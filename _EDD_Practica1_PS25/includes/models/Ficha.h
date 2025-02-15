//
// Created by Carlos Cotom on 14/02/2025.
//

#ifndef FICHA_H
#define FICHA_H


class Ficha {

private:
    char letra;
    int valor;

public:
    Ficha();
    Ficha(char letra, int valor);

    char getLetra();
    void setLetra(char letra);

    int getValor();
    void setValor(int valor);

};



#endif //FICHA_H
