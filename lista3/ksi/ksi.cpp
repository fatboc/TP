#include"ksi.hpp"
using namespace std;

AdressBook::AdressBook( string ){

    string imie;
    string adres;
    string linia;
    string linia2;
    plik.open("test.txt", ios::in);
    if(!plik.is_open())
        cout<<"Nie udalo sie otworzyc pliku"<<endl;
    do{
        getline(plik, linia);
        std::cout<<linia<<endl;
        getline(plik, linia2);
        std::cout<<linia2<<endl;
        book[linia] = linia2;
    }
    while(!plik.eof());
    plik.close();
    if(plik.is_open())
        cout<<"Nie udalo sie zamknac pliku"<<endl;

}

AdressBook::~AdressBook(){
    plik.open("test.txt", ios::trunc | ios::out);
    if(!plik.is_open())
       cout<<"Nie udalo sie otworzyc pliku"<<endl;
    for(map<string, string>::iterator itr = book.begin(), koniec = book.end(); itr != koniec; ++itr){
        plik << itr->first <<endl;
        plik << itr->second <<endl;
    }
    plik.close();
    book.clear();
    //if(plik.is_open())
    //    cout<<"Nie udalo sie zamknac pliku"<<endl;
}

void AdressBook::Add(string name, string adress){
    book[name] = adress;
}

void AdressBook::Delete(string name){
    book.erase(name);
}

void AdressBook::UpdateName(string name1, string name2){
    book[name2]=book[name1];
    book.erase(name1);
}

void AdressBook::UpdateAdress(string name, string adress){
    book[name] = adress;
}

void AdressBook::ShowAdress(string name){
    cout << book[name] << endl;
}

void AdressBook::ShowAll(){
    for(map<string, string>::iterator itr = book.begin(), koniec = book.end(); itr != koniec; ++itr){
        cout << itr->first << "-->" << itr->second <<endl;
    }
}
