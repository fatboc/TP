#include<iostream>

const int DEF_SIZE = 16;

class VectorInt{

    int * value;
    int el_no;
    int cap;

    public:
    VectorInt();
    VectorInt(int _size);
    VectorInt(const VectorInt & _v);
    ~VectorInt();
    void operator=(const VectorInt & _v);
    int operator[](int _index);
    int at(int _index);
    int insert(int _index, int _value);
    int pushBack(int _value);
    int popBack();
    int shrinkToFit();
    int clear();
    int size();
    int capacity();
    friend std::ostream& operator<< (std::ostream & os, VectorInt & _v);
};
