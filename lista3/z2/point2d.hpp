/*point2d.hpp*/
/*Plik nagłówkowy klasy Point2d.hpp*/
#ifndef POINT2D_HPP_INCLUDED
#define POINT2D_HPP_INCLUDED
#include <iostream>

class Point2d{
    public:
        //konstruktor bez argumentów zwraca punkt (0,0)
        Point2d();

        //destruktor nie jest zadeklarowany
        //będzie wykorzystywany domyślny
        //~Point2d();

        //konstruktor pobierający współrzędne
        Point2d(double, double);

        //konstruktor kopiujący
        Point2d(const Point2d& other);

        //przeciążony operator przypisania
        Point2d& operator= (const Point2d& other);

        //gettery i settery
        double getX();
        double getY();
        double getR();
        double getPhi();
        void setXY(double, double);
        void setRPhi(double, double);
        void jednokladnosc(double);
        void obrot(double);

    private:
        //współrzędne punktu jako pola prywatne
        double _r;
        double _phi;
};

//deklaracja przeciążonego operatora <<
//na potrzeby wyświetlania współrzędnych punktu
std::ostream& operator<<(std::ostream& out, Point2d& p);

#endif // POINT2D_HPP_INCLUDED
