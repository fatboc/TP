#include<iostream>
#include <stdlib.h>
#include <fstream>
#define N 3

enum Stan{
    puste,
    kolko,
    krzyzyk,
};

class TicTacToe{
    Stan plansza [3][3];
    Stan gracz;
    Stan zwyciezca;

    public:
    void rysuj();
    void graj();
    bool ruch();
    bool szukaj(int x, int y);
    bool koniec();
    bool poprawny(const char * c_x, const char * c_y);
    bool zapisz();
};

