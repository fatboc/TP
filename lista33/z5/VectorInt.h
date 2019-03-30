#include<iostream>

const int DEF_SIZE = 16

class VectorInt{

    int * value;
    int size;

    public:
    VectorInt();
    VectorInt(int _size);
    VectorInt(const & VectorInt _v);
    ~VectorInt();
    operator=(const & VectorInt _v);
    operator[](int _index);
    int at(int _index);
    int insert(int _index, int _value);
    int pushBack(int _value);
    int popBack();
    int shrinkToFit();
    int clear();
    int size();
    int capaity();
    std::ostream& operator<< (std::ostream & os);
}
