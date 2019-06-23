#include <iostream>
#include <map>
#include <fstream>

using namespace std;

void nowy(map<string, string> & adresy);
void przegladaj(map<string, string> & adresy);
bool laduj(map<string, string> & adresy);
bool zapisz(map<string, string> & adresy);

int main()
{
    map<string, string> adresy;

    if (!laduj(adresy))
    {
        cout << "Blad odczytu." << endl;
        return -1;
    }
    char c;

    do
    {
        cout << "Wybierz dzialanie:" << endl;
        cout << "0. Zakoncz program" << endl;
        cout << "1. Wprowadz nowy rekord" << endl;
        cout << "2. Przegladaj istniejace" << endl;
        cout << "3. Zapisz dane" << endl;

        cin.get(c);

        switch(c)
        {
        case '0':
            zapisz(adresy);
            return 0;
        case '1':
            nowy(adresy);
            break;
        case '2':
            przegladaj(adresy);
            break;
        case '3':
            zapisz(adresy);
            break;
        default:
            cout << "Wybierz poprawny numer dzialania." << endl;
        }

        cin.ignore(1000, '\n');


    }
    while(1);
}

void nowy(map<string, string> & adresy)
{
    char nazwa[1000];
    string email;

    // do{
    cout << "Wprowadz nazwe:" << endl;
    cin.ignore(1000, '\n');
    cin.getline(nazwa, 1000);
    //}while (nazwa!="");

    //do{
    cout << "Wprowadz adres email:" << endl;
    cin >> email;
    //}while (email!="");

    // adresy.emplace(nazwa, email);
    adresy.insert( pair<string, string> (nazwa, email));
}

void przegladaj(map<string, string> & adresy)
{
    cout << "Lp. nazwa adres" << endl;;
    int i=0, n;
    for (map<string, string>::iterator it=adresy.begin(); it!=adresy.end(); ++it)
    {
        //  ++i;
        cout << ++i << " " << it->first << " " << it->second << endl;
    }
    cout << endl << endl;

    cout << "Podaj nr wpisu do modyfikacji, badz 0 aby wyjsc:" << endl;
            cin.ignore(1000, '\n');

    cin >> n;
    if (n==0)
        return;
    i=0;
    string nmail;
    for (map<string, string>::iterator it=adresy.begin(); it!=adresy.end(); ++it){
        i++;
        if(i==n){
            cout << "1 - edytuj; 2 - usun; 0 - wyjdz" << endl;
                    cin.ignore(1000, '\n');

            char c;
            cin >> c;
            switch(c){
            case '0':
                return;
            case '1':
                cout << "Podaj nowy adres email:" << endl;
                cin.ignore(1000, '\n');
                cin >> nmail;
                it->second = nmail;
                                return;

            case '2':
                adresy.erase(it);

                cout << "Usunieto" << endl;
                                return;

            default:
                cout << "Nie rozpoznano wyboru." << endl;
                                return;

            }
        }
    }
    cout << "Nie znaleziono wpisu nr " << i << endl;
}

bool laduj(map<string, string> &adresy)
{
    ifstream in("adresy.txt");
    if (!in)
    {
        return false;
    }

    char c;

    while(in)
    {
        char nazwa[1000];
        string email;

        in.getline(nazwa, 1000 );

        in >> email;
        in.ignore(1000, '\n');

        if(nazwa!="" && email!="")
            adresy.insert( pair<string, string> (nazwa, email));
    }
    in.close();
    return true;
}

bool zapisz(map<string, string> &adresy)
{
    ofstream out;
    out.open("adresy.txt");

    for(map<string, string>::iterator it=adresy.begin(); it!=adresy.end(); ++it){
        out << it->first << endl << it-> second << endl;
    }

    cout << "Zapisano." << endl;
    out.close();
}
