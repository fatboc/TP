#include <iostream>
#include <map>

using namespace std;

void nowy(map<string, string> adresy);
void przegladaj(map<string, string> adresy);

int main(){
    map<string, string> adresy;
    char c;

    do{
        cout << "Wybierz dzialanie:" << endl;
        cout << "0. Zakoncz program" << endl;
        cout << "1. Wprowadz nowy rekord" << endl;
        cout << "2. Przegladaj istniejace" << endl;

        cin.get(c);

        switch(c){
        case '0':
            return 0;
        case '1':
            nowy(adresy);
            break;
        case '2':
            przegladaj(adresy);
            break;
        default:
            cout << "Wybierz poprawny numer dzialania.";
        }

    } while(1);
}

void nowy(map<string, string> adresy){
    char nazwa[1000];
    string email;

    do{
        cout << "Wprowadz nazwe:" << endl;
        cin.getline(nazwa, 1000);
    }while (nazwa!="");

    do{
        cout << "Wprowadz adres email" << endl;
        cin >> email;
    }while (email!="");

    adresy.emplace(nazwa, email);

}

void przegladaj(map<string, string> adresy){

}
