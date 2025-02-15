//
// Created by Carlos Cotom on 15/02/2025.
//

#ifndef PALABRASCONTROLLER_H
#define PALABRASCONTROLLER_H
#include <string>


class PalabrasController {

public:
    PalabrasController();

    int cargarPalabras(std::string &nombreArchivo, std::string palabrasExtraidas[]);
    void ordenarPalabras(std::string palabrasExtraidas[], int cantidadPalabras);
    bool isPalabraValida(std::string &palabra, std::string palabraExtraidas[], int cantidadPalabras);

};



#endif //PALABRASCONTROLLER_H
