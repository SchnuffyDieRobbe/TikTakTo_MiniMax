//
// Created by florian on 8/24/25.
//

#ifndef TIKTAKTO_MINIMAX_SPIELFELD_H
#define TIKTAKTO_MINIMAX_SPIELFELD_H
#include <string>
#include <vector>


class Spielfeld {
public:
    std::vector<std::vector<int>> feld;

     Spielfeld();
    void print();
    int Bewertung();
    std::pair<std::tuple<int,int,int>,bool> wendeZugAn(std::string zug, int player);
    void Undo (std::pair<std::tuple<int,int,int>,bool> backup);
    bool isTerminal();
};


#endif //TIKTAKTO_MINIMAX_SPIELFELD_H