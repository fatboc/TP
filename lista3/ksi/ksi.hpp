#include <iostream>
#include<string>
#include<map>
#include<fstream>
using namespace std;

class AdressBook{
    private:
        map<string, string> book;
        fstream plik;
    public:
        AdressBook(const AdressBook&);
        AdressBook(string);
        ~AdressBook();
        void Add(string, string);
        void Delete(string);
        void UpdateName(string, string);
        void UpdateAdress(string, string);
        void ShowAll();
        void ShowAdress(string);
};

