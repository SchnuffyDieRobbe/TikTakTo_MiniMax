#include <iostream>

#include "MiniMax.h"
#include "Spielfeld.h"
int currPlayer = 1;

// 1 --> X
// 2 --> O

void test () {
    auto testFeld = Spielfeld();
    testFeld.print();
    auto backup = testFeld.wendeZugAn("2,2,X",1);
    testFeld.print();
    testFeld.Undo(backup);
    testFeld.print();
}

int main(){

    auto feld = Spielfeld();
    auto max = MiniMax();

    while (!feld.isTerminal()) {
        feld.print();

        if (currPlayer == 1) {
            std::cout << "Spieler " << currPlayer << " (X) ist dran:" << std::endl;
            std::cout << "Zug hat Form Zeile,Spalte,X, z.B. 1,1,X \n" << std::endl;
            std::string zug;
            std::cin >> zug;

            if (feld.wendeZugAn(zug,currPlayer).second) {
                currPlayer = (currPlayer == 1) ? 2 : 1;
            }
        } else if (currPlayer == 2) {
            std::cout << "KI (O) denkt..." << std::endl;
            auto zug = max.getBestMove(feld,currPlayer);
            std::cout << "KI spielt: " << zug << std::endl;

            if (feld.wendeZugAn(zug,currPlayer).second) {
                currPlayer = (currPlayer == 1) ? 2 : 1;
            }
        }
    }

    // Spiel ist beendet
    feld.print();
    std::cout << "Spiel beendet!" << std::endl;

    return 0;
}

