//
// Created by florian on 8/24/25.
//

#include "Spielfeld.h"
#include <iostream>
#include <sstream>

extern int ZuBewertenderSpieler;

Spielfeld::Spielfeld() {
    feld = std::vector<std::vector<int>>(4, std::vector<int>(4, 0));

for (int i = 0 ; i < 4 ; i++) {
    feld[i][0] = i;
}
    for (int j = 0 ; j < 4 ; j++) {
        feld[0][j] = j;
    }

    for (int i = 1; i < 4 ; i++) {
        for (int j = 1; j < 4 ; j++) {
            feld[i][j] = 0;
        }
    }
}

void Spielfeld::print() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == 0 || j == 0) {
                // Zeilen- und Spaltennummern anzeigen
                std::cout << feld[i][j] << " ";
            } else {
                // Spielfeld anzeigen (0=leer, 1=X, 2=O)
                if (feld[i][j] == 0) {
                    std::cout << ". ";
                } else if (feld[i][j] == 1) {
                    std::cout << "X ";
                } else if (feld[i][j] == 2) {
                    std::cout << "O ";
                }
            }
        }
        std::cout << std::endl; // Neue Zeile nach jeder Reihe
    }
}

int  Spielfeld::Bewertung() {
    auto checkThree = [&](int a, int b, int c) {
        return a == b && b == c && a != 0;
    };

    // Zeilen
    for (int i = 1; i < 4; i++) {
        if (checkThree(feld[i][1], feld[i][2], feld[i][3])) {
            if (feld[i][1] != ZuBewertenderSpieler) {
                return -1; // Verloren
            }
            return 1; // Gewonnen
        }
    }

    // Spalten
    for (int j = 1; j < 4; j++) {
        if (checkThree(feld[1][j], feld[2][j], feld[3][j])) {
            if (feld[1][j] != ZuBewertenderSpieler) {
                return -1; //verloren
            }
            return 1; //gewonnen
        }
    }

    // Diagonalen
    if (checkThree(feld[1][1], feld[2][2], feld[3][3])) {
        if (feld[1][1] != ZuBewertenderSpieler) {
            return -1; //verloren
        }
        return 1; //gewonnen
    }
    if (checkThree(feld[1][3], feld[2][2], feld[3][1])) {
        if (feld[1][3] != ZuBewertenderSpieler) {
            return -1; //verloren
        }
        return 1; //gewonnen
    }

    return 0;
}

bool Spielfeld::isTerminal() {
    auto checkThree = [&](int a, int b, int c) {
        return a == b && b == c && a != 0;
    };
    
    // Zeilen
    for (int i = 1; i < 4; i++) {
        if (checkThree(feld[i][1], feld[i][2], feld[i][3])) return true;
    }
    
    // Spalten
    for (int j = 1; j < 4; j++) {
        if (checkThree(feld[1][j], feld[2][j], feld[3][j])) return true;
    }
    
    // Diagonalen
    if (checkThree(feld[1][1], feld[2][2], feld[3][3])) return true;
    if (checkThree(feld[1][3], feld[2][2], feld[3][1])) return true;

    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            if (feld[i][j] == 0) return false; // Noch freie Felder
        }
    }
    return true;
}

std::pair<std::tuple<int,int,int>,bool> Spielfeld::wendeZugAn(std::string zug, int player) {
    std::stringstream ss(zug);

    int i,j;
    char content;
    char sep1,sep2;

    if ((ss >> i >> sep1 >> j >> sep2 >> content) &&
        sep1 == ',' && sep2 == ',' && ss >> std::ws && ss.eof()) {
        int Zahl;
        if (content == 'X' || content == 'x') {
            Zahl = 1;
        }else if (content == 'O' || content == 'o') {
            Zahl = 2;
        }

        if (Zahl != player) {
            std::cout << "Falscher Spieler !" << std::endl;
            return {{0,0,0},false};
        }
        if (feld[i][j] != 0) {
            std::cout << "Ungültiger Zug! \n";
            return{{0,0,0},false};
        }
        if (i < 1 || i > 3 || j < 1 || j > 3) {
            std::cout << "Zug liegt nicht im Spielfeld!" << std::endl;
            return {{0,0,0},false};
        }
        auto oldValue = feld[i][j];
        feld[i][j] = Zahl;
        return {{i,j,oldValue},true};

        } else {
        std::cout << "Ungültiges Zugformat!" << std::endl;
            return{{0,0,0},false};
        }
    return {{0,0,0},false};
}

void Spielfeld::Undo(std::pair<std::tuple<int, int, int>, bool> backup) {
    auto saveState = backup.first;
    bool valid = backup.second;
    if (valid) {
        feld[std::get<0>(saveState)][std::get<1>(saveState)] = std::get<2>(saveState);
    }
}


