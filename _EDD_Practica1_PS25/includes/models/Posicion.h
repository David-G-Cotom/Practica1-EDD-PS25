//
// Created by Carlos Cotom on 17/02/2025.
//

#ifndef POSICION_H
#define POSICION_H



class Posicion {

private:
    int x;
    int y;

public:
    Posicion(int x, int y);

    int getX();
    void setX(int x);

    int getY();
    void setY(int y);

};



#endif //POSICION_H
