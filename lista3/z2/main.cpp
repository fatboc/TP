/*main.cpp*/
/*Program demonstrujący możliwości
klasy Point2d.*/
#include <iostream>
#include "point2d.hpp"

using namespace std;

int main()
{
    //obiekt a utworzony z wykorzystaniem konstruktura domyślnego
    Point2d a;
    //do wyświetlania wykorzystujemy przeciążony operator <<
    //std::ostream& operator<<(std::ostream& out, Point2d& p);
    cout << "a = " << a << endl;
    //metoda setXY ustawia współrzędne punktu
    a.setXY(3, 4);
    cout << "a = " << a << endl;

    //obiekt b utworzony z wykorzystaniem konstruktora pobierającego
    //dwie liczby - współrzędne punktu
    Point2d b(-2,-1);
    cout << "b = " << b << endl;

    //obiekt c utworzony z wykorzystaniem konstruktora kopiującego
    Point2d c(b);
    cout << "c = " << c << endl;

    //wykorzystanie metod get do odczytania współrzędnych punktu
    cout << "a.x = "   << a.getX() << endl;
    cout << "a.y = "   << a.getY() << endl;
    cout << "a.r = "   << a.getR() << endl;
    cout << "a.phi = " << a.getPhi() << endl;

    //metoda setRPhi ustawia współrzędne punktu na podstawie
    //współrzędnych biegunowych
    b.setRPhi(5,1);
    cout << "b = " << b << endl;
    b.jednokladnosc(-1.0);
    cout << "b = " << b << endl;
    b.obrot(3.1415/4.0);
    cout << "b = " << b << endl;

    return 0;
}
