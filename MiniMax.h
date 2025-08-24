//
// Created by florian on 8/24/25.
//

#ifndef TIKTAKTO_MINIMAX_MINIMAX_H
#define TIKTAKTO_MINIMAX_MINIMAX_H
#include "Spielfeld.h"


class MiniMax {
public:
    int minimieren(Spielfeld& board,int player);
    int maximieren(Spielfeld& board,int player);
    std::string getBestMove(Spielfeld& board,int player);
    std::vector<std::string> getAllMoves(Spielfeld board, int player);
};


#endif //TIKTAKTO_MINIMAX_MINIMAX_H