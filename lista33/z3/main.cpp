#include "TicTacToe.h"

using namespace std;

int main()
{
    TicTacToe t;
    t.graj();
}

void TicTacToe::rysuj(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            //cout << setw(3);
            switch(plansza[i][j]){
                case puste:
                    cout << "   ";
                    break;
                case kolko:
                    cout << " O ";
                    break;
                case krzyzyk:
                    cout << " X ";
                    break;
            }
        }
        cout << endl;
    }
}

void TicTacToe::graj(){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            plansza[i][j]=puste;
        }
    }

    gracz = kolko;

    while (!koniec()){
        if(ruch()){
            cout  << "Wygral gracz " << gracz << endl;
            break;
        }
        if (gracz==1)
            gracz=krzyzyk;
        else gracz=kolko;
        rysuj();
    }

}

bool TicTacToe::ruch(){
    int x=0;
    int y=0;

    do{
        cout << "Podaj x-wspolrzedna ruchu gracza " << gracz << endl;
        cin >> x;
        cout << "Podaj y-wspolrzedna ruchu gracza " << gracz << endl;
        cin >> y;
    }while (!poprawny(x, y));

    plansza[x][y]=gracz;

    if (szukaj(x, y))
        return true;

    return false;
}

bool TicTacToe::szukaj(int x, int y){
    int c;
    Stan s=gracz;

    c=0;
    for (int i=0; i<3; i++){
        if (plansza[(x+i)%3][y]==s)
            c++;
    }
    if (c==3)
        return true;

    c=0;
    for (int i=0; i<3; i++){
        if (plansza[x][(y+i)%3]==s)
            c++;
    }
    if (c==3)
        return true;

    c=0;
    for (int i=0, j=0; i<3, j<3; i++, j++){
        if (plansza[(x+i)%3][(y+j)%3]==s)
            c++;
    }
    if (c==3)
        return true;

    c=0;
    for (int i=0, j=2; i<3, j>=0; i++, j--){
        if (plansza[(x+i)%3][(y+j)%3]==s)
            c++;
    }
    if (c==3)
        return true;

        return false;
}

bool TicTacToe::koniec(){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (plansza[i][(j)%3]==puste)
                return false;
        }
    }
    return true;
}

bool TicTacToe::poprawny(int x, int y){
     if (x>N-1 || y>N-1 || x<0 || y<0){
        cout << "Podane pole nie istnieje" << endl;
        return false;
    }

    if(plansza[x][y]!=puste){
        cout << "Podane pole jest zajęte" << endl;
        return false;
    }

    return true;
}
