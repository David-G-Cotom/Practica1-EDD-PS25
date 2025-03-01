#include <iostream>
#include <ostream>

#include "includes/controllers/GameController.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    std::cout << "---------- Bienvenido al Juego de SCRABBLE ----------" << std::endl;
    auto *game = new GameController();
    game->jugar();
    delete game;

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.