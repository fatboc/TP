#include "TicTacToe.h"



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
    string c_x, c_y;

    if(gracz==kolko){
        do{
        cout << "Podaj x-wspolrzedna ruchu gracza " << gracz << endl;
        cin >> c_x;
        cout << "Podaj y-wspolrzedna ruchu gracza " << gracz << endl;
        cin >> c_y;
        //cin.ignore(1000, '\n');
    }while (!poprawny(c_x.c_str(), c_y.c_str()));

    x=atoi(c_x.c_str());
    y=atoi(c_y.c_str());

    plansza[x][y]=gracz;


    if (szukaj(x, y))
        return true;

    return false;
    }

    else return minimax();



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

bool TicTacToe::poprawny(const char * c_x, const char * c_y){

    string s1 = "Niepoprawne dane.";
    string s2 = "Pole zajete.";
    string s3 = "Niespodziewany symbol.";

    try{
        if (!(*c_x>='0' && *c_x<='9') || !(*c_y>='0' && *c_y<='9')) throw s3;
        int x = atoi(c_x);
        int y = atoi(c_y);
        if (x>N-1 || y>N-1 || x<0 || y<0) throw s1;
        if(plansza[x][y]!=puste) throw s2;
    }

    catch(string s){
        cout << s << endl;
        return false;
    }

    return true;
}

bool TicTacToe::zapisz(){
    ofstream out;

    string s = "Blad pliku.";

    try{
        out.open("gra.txt");

        if(!out) throw s;

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
            //cout << setw(3);
                switch(plansza[i][j]){
                case puste:
                    out << "   ";
                    break;
                case kolko:
                    out << " O ";
                    break;
                case krzyzyk:
                    out << " X ";
                    break;
                }
            }
        out << endl;
        }

        out.close();
    }
    catch(string s){
        cout << s << endl;
        return false;
    }
    catch(...){
        cout << "Blad zapisu." << endl;
        return false;
    }

    return true;
}


bool TicTacToe::minimax(){
    bool dostepne [3][3];
    int wynik=0, tmp, x=-1, y=-1, i, j;

    for (i=0; i<3; i++){
        for (j=0; j<3; j++){
            if(gracz==kolko &&  (plansza[i][j]==puste))
               tmp  = mmmax(i, j);
            else if(gracz==krzyzyk &&  (plansza[i][j]==puste))
                tmp = mmmin(i, j);
            }

            if((gracz==kolko && wynik > tmp) || (gracz==krzyzyk && wynik < tmp)){
                wynik=tmp;
                x=i;
                y=j;
            }
    }

    plansza[x][y]=gracz;
    return szukaj(x, y);
}

int TicTacToe::mmmax(int x, int y){
    if (szukaj(x, y) && gracz == kolko) return 10;
    else if(szukaj(x, y) && gracz==krzyzyk) return -10;
    else return 0;

    int wynik=0, tmp=0;

    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++){
            if (plansza[x][y]==puste){
                plansza[i][j]=gracz;
                gracz=krzyzyk;
                tmp = mmmin(i, j);
                if (wynik < tmp)
                    wynik = tmp;
                plansza[i][j]=puste;
                gracz=kolko;
            }
        }

    return wynik;
}

int TicTacToe::mmmin(int x, int y){
    if (szukaj(x, y) && gracz == kolko) return 10;
    else if(szukaj(x, y) && gracz==krzyzyk) return -10;
    else if (koniec()) return 0;

    int wynik=0, tmp=0;

    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++){
            if (plansza[x][y]==puste){
                plansza[i][j]=gracz;
                gracz  = kolko;
                tmp = mmmax(i, j);
                if(wynik > tmp)
                    wynik=tmp;
                plansza[i][j]=puste;
                gracz = krzyzyk;
            }
        }

    return wynik;
}
