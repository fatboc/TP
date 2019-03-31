#include<iostream>
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
    bool poprawny(int x, int y);
};

