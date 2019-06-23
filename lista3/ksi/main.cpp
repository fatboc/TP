#include<iostream>
#include"ksi.hpp"
#include<string>
#include<map>
#include<fstream>
using namespace std;


int main(){
    string test;
    string imie;
    string imie1;
    string adres;
    int chs;
    AdressBook nowa(test);
    while(true){
        cout<<" \n Operacje ksiazki adresowej: "<<endl;
        cout<<" ----------------------------"<<endl;
        cout<<" 1:Dodawanie nowego adresu"<<endl;
        cout<<" 2:Usuwanie adresu"<<endl;
        cout<<" 3:Aktualizowanie imienia osoby"<<endl;
        cout<<" 4:Aktualizowanie adresu osoby"<<endl;
        cout<<" 5:Wyswietlanie adresu podanej osoby"<<endl;
        cout<<" 6:Wywietlanie wszystkich adresow"<<endl;
        cout<<" 7:Zamkniecie programu"<<endl;
        cout<<" -----------------------------"<<endl;
        cout<<" Prosze podac wybor: "<<endl;
        cin>>chs;
        if(chs==1){
            cout<<"   Prosze podac imie nowego adresu:"<<endl;
            cin>>imie;
            cout<<"   Prosze podac adres nowego adresu:"<<endl;
            cin>>adres;
            nowa.Add(imie,adres);
        }
        if(chs==2){
            cout<<"   Prosze podac imie osoby do usuniecia"<<endl;
            cin>>imie;
            nowa.Delete(imie);
        }
        if(chs==3){
            cout<<"   Prosze podac imie starego adresu:"<<endl;
            cin>>imie;
            cout<<"   Prosze podac imie nowego adresu:"<<endl;
            cin>>imie1;
            nowa.UpdateName(imie,imie1);
        }
        if(chs==4){
            cout<<"   Prosze podac imie adresu:"<<endl;
            cin>>imie;
            cout<<"   Prosze podac nowy adres:"<<endl;
            cin>>adres;
            nowa.UpdateAdress(imie,adres);
        }
        if(chs==5){
            cout<<"   Prosze podac imie szukanej osoby:"<<endl;
            cin>>imie;
            nowa.ShowAdress(imie);
        }
        if(chs==6){
            nowa.ShowAll();
        }
        if(chs==7){
                delete nowa;
            break;
        }

    }
}
