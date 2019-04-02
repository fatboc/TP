/*point2d.cpp*/
/*Plik źródłowy klasy Point2d.hpp*/
#include"point2d.hpp"
#include<iostream>
#include<cmath>
#define M_PI 4*atan(1.)


//konstruktor bez argumentów zwraca punkt (0,0)
//wykorzystano konstruktor z listą inicjalizacyjną
Point2d::Point2d()
    : _r(0)
    , _phi(0){
}

//konstruktor pobierający współrzędne
//wykorzystano konstruktor z listą inicjalizacyjną
Point2d::Point2d(double r, double phi)
    : _r(r)
    , _phi(phi){
}

//konstruktor kopiujący
//wykorzystano konstruktor z listą inicjalizacyjną
Point2d::Point2d(const Point2d& other)
    : _r(other._r)
    , _phi(other._phi){
}

//przeciążony operator przypisania
Point2d& Point2d::operator= (const Point2d& other){
    //wykorzystano wskaźnik this pokazujący
    //na "ten" obiekt
    this->_phi = other._phi;
    this->_r = other._r;
    //operator zwraca "ten" obiekt, aby można było
    //wykonać wielokrotne przypisanie
    return *this;
}

//współrzędna x
double Point2d::getX(){
    return _r*cos(_phi);
}

//współrzędna y
double Point2d::getY(){
    return _r*sin(_phi);
}

//współrzędna r
double Point2d::getR(){
    return _r;
}

//współrzędna phi
double Point2d::getPhi(){
    return _phi;
}

void Point2d::setXY(double x, double y){
    _r = sqrt(x*x + y*y);
    _phi = atan2(y,x);
}

void Point2d::setRPhi(double r, double phi){
//przypisanie z wykorzystaniem wskaźnika this oraz wprost
    _r = r;
    this->_phi = phi;
}

//przeciążony operator<< dla wypisywania
std::ostream& operator<<(std::ostream& out, Point2d& p){
    return out << "[" << p.getR() << ", " << p.getPhi() << "]";
}

void Point2d::jednokladnosc(double k){
    _r*=k;
}

void Point2d::obrot(double phi){
    _phi+=phi;
}
