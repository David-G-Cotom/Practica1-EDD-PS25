//
// Created by Carlos Cotom on 15/02/2025.
//

#ifndef PALABRASCONTROLLER_H
#define PALABRASCONTROLLER_H
#include <string>

#include "../structs/LinkedList.h"


class PalabrasController {

public:
    PalabrasController();

    LinkedList<std::string> *cargarPalabras(std::string &nombreArchivo);
    void ordenarPalabras(LinkedList<std::string> *palabrasExtraidas);
    bool isPalabraValida(std::string &palabra, LinkedList<std::string> *palabraExtraidas);

};



#endif //PALABRASCONTROLLER_H
