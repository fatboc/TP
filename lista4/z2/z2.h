#include <iostream>

using namespace std;


template<class K, class V>
class node{
    K key;
    V value;
    node * left;
    node * right;

    public:
    node();
    node(K _key, V _value);
    ~node();
    bool add(K _key, V _value);
    bool remove(K _key);
};

template<class K, class V>
class mapp{
    node<K, V> * root;

    public:
    mapp();
    int add(K _key, V _value);
    int remove(K _key);
    void print();
};
