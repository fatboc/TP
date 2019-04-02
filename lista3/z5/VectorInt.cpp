#include "VectorInt.h"

VectorInt::VectorInt(){
    value = new int[DEF_SIZE];
    el_no = 0;
    cap = DEF_SIZE;
}

VectorInt::VectorInt(int _size){
    value = new int[_size];
    el_no = 0;
    cap = _size;
}

VectorInt::VectorInt(const VectorInt & _v){
    value = new int[_v.cap];
    el_no = _v.el_no;
    cap = _v.cap;

    for (int i=0; i<el_no; i++){
        value[i] = _v.value[i];
    }
}

int VectorInt::operator[](int _index){
    if(0 < _index && _index < el_no)
        return value[_index];
    else return -1;
}

void VectorInt::operator=(const VectorInt & _v){
    delete[] value;
    value = new int[_v.cap];
    el_no = _v.el_no;
    cap = _v.cap;

    for (int i=0; i<el_no; i++){
        value[i] = _v.value[i];
    }
}

VectorInt::~VectorInt(){

    delete[] value;
    //delete this; //XD
}

int VectorInt::at(int _index){
    if(0 < _index && _index < el_no)
        return value[_index];
    else return NULL;
}

int VectorInt::insert(int _index, int _value){
    int * nvalue = new int[el_no+1];

    for (int i=0; i<_index; i++){
        nvalue[i] = value[i];
    }
    nvalue[_index]=_value;

    for (int i=_index; i<el_no; i++){
        nvalue[i+1] = value[i];
    }

    delete[] value;
    value = nvalue;
    el_no++;
    cap++;

    return ++_index;
}

int VectorInt::pushBack(int _value){
    if(!(cap > el_no)){
        int * nvalue = new int[el_no+1];

        for (int i=0; i<el_no; i++){
            nvalue[i] = value[i];
        }
        delete[] value;
        //value = new int[]
        value = nvalue;
        cap++;
    }
    value[el_no] = _value;
    el_no++;

    return (el_no-1);
}

int VectorInt::popBack(){
    int * nvalue = new int[--el_no];
    for (int i=0; i<el_no; i++)
        nvalue[i] = value[i];

    delete[] value;
    value = nvalue;
    cap--;

    return (el_no-1);
}

int VectorInt::shrinkToFit(){
    if (cap > el_no){
        int * nvalue = new int[el_no];
        for (int i=0; i<el_no; i++)
            nvalue[i] = value[i];

        delete[] value;
        value = nvalue;
        cap = el_no;
    }
    return (el_no-1);
}

int VectorInt::clear(){
    delete[] value;
    value = NULL;
    el_no=0;
    cap=0;

    return el_no;
}

int VectorInt::size(){
    return el_no;
}

int VectorInt::capacity(){
    return cap;
}

std::ostream& operator<< (std::ostream & os, VectorInt & _v){
    for (int i=0; i<_v.el_no; i++){
        os << _v.value[i] << " ";
    }
    return os;
}
