#include "VectorInt.h"

VectorInt::VectorInt(){
    int * value = new int[DEF_SIZE];
    size = DEF_SIZE;
}

VectorInt::VectorInt(int _size){
    int * value = new int(_size);
    size = _size;
}

VectorInt::VectorInt(const & VectorInt _v){
    int * value = new int(_v.size);
    size = _v.size;

    for (int i=0; i<size; i++){
        value[i] = _v[i];
    }
}

VectorInt::operator[](int _index){
    if(0 < _index && _index < size)
        return value[_index]
    else return NULL;
}

VectorInt::operator=(const & VectorInt _v)

VectorInt::~VectorInt(){
    delete[] value;
    delete this; //XD
}
