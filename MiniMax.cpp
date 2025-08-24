//
// Created by florian on 8/24/25.
//

#include "MiniMax.h"

#include <limits.h>

 int ZuBewertenderSpieler = 0;

std::vector<std::string> MiniMax::getAllMoves(Spielfeld board, int player) {

    std::vector<std::string> allMoves;
    std::string content;
    if (player == 1) {
        content = "X";
    }else {
        content = "O";
    }

    for (int i = 1; i < 4 ; i++) {
        for (int j = 1 ; j < 4 ; j++) {
            if (board.feld[i][j] == 0) {
                std::string zug = std::to_string(i)  + "," + std::to_string(j) + "," + content;
                allMoves.push_back(zug);
            }
        }
    }
    return allMoves;
}

int MiniMax::minimieren(Spielfeld &board, int player) {
    if (board.isTerminal()) {
       return board.Bewertung();
    }

    auto alleZüge = getAllMoves(board,player);

    int Iniwert = INT_MAX;

    for (auto z : alleZüge) {
        auto backup = board.wendeZugAn(z,player);

        auto opp = (player == 1) ? 2 : 1;
        int wert = maximieren(board,opp);

        board.Undo(backup);

        if (wert < Iniwert) {
            Iniwert = wert;
        }
    }
    return Iniwert;
}

int MiniMax::maximieren(Spielfeld &board, int player) {
    if (board.isTerminal()) {
        return board.Bewertung();
    }

    int IniWert = INT_MIN;
    auto züge = getAllMoves(board,player);

    for (auto z : züge) {
        auto backup = board.wendeZugAn(z,player);
        auto opp = (player == 1) ? 2 : 1;

        int wert = minimieren(board,opp);

        board.Undo(backup);

        if (wert > IniWert) {
            IniWert = wert;
        }
    }
    return IniWert;
}

std::string MiniMax::getBestMove(Spielfeld &board, int player) {
    ZuBewertenderSpieler = player;
    std::string bestMove;
    int bestWert = INT_MIN; // Wir wollen maximieren!

    auto züge = getAllMoves(board,player);

    for (auto z : züge) {
        auto backup = board.wendeZugAn(z,player);

        auto opp = (player == 1) ? 2 : 1;
        auto wert = minimieren(board,opp);

        board.Undo(backup);

        if (wert > bestWert) {
            bestWert = wert;
            bestMove = z;
        }
    }
    return bestMove;
}



