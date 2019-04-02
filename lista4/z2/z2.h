#include <iostream>

using namespace std;

template<class K, class V>
class mapp;

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
    void remove(K _key, node * curr, node * parent, int dir);
    node * find_max();

    void print();
    friend class mapp<K, V>;
};

template<class K, class V>
class mapp{
    node<K, V> * root;

    public:
    mapp();
    int add(K _key, V _value);
    void remove(K _key);
    void print();
    friend class node<K,V>;
};

template<class K, class V>
mapp<K, V>::mapp() : root(NULL){};

template<class K, class V>
node<K, V>::node(K _key, V _value) : key(_key), value(_value), left(NULL), right(NULL) {};

template<class K, class V>
bool node<K, V>::add(K _key, V _value){
    if(key==_key){
        value=_value;
        return true;
    }

    else if (key > _key){
        if(left)
            left->add(_key, _value);

        else{
            left = new node(_key, _value);
            return true;
        }
    }

    else{
        if(right)
            right->add(_key, _value);

        else{
            right = new node(_key, _value);
            return true;
        }
    }
    return false;
}

template<class K, class V>
int mapp<K, V>::add(K _key, V _value){
    if (!root){
        root = new node<K, V>(_key, _value);
        return 1;
    }

    root->add(_key, _value);
    return 0;
}

template<class K, class V>
void node<K, V>::print(){
    if (left)
        left->print();
    cout << key << "->" << value << endl;
    if (right)
        right->print();
}

template<class K, class V>
void mapp<K, V>::print(){
    if(!root)
        return;

    root->print();
}
//
//template<class K, class V>
//bool node<K,V>::remove(K _key){
//    if(key==_key){
//        if(!left && !right)
//            delete &this;
//            &this=NULL;
//        else if(!left)
//    }
//    else if (_key > key){
//        right->remove(_key);
//    }
//    else{
//        left->remove(_key);
//    }
//
//    return false;
//}

template<class K, class V>
void node<K,V>::remove(K _key, node * curr, node * parent, int dir){
    if(!curr)
        return;

    else if(curr->key>_key){
        remove(_key, curr->left, curr, -1);
    }

    else if(curr->key<_key){
        remove(_key, curr->right, curr, 1);
    }

    else{
        if (!curr->left && !curr->right){
            switch (dir){
                case -1:
                    parent->left=NULL;
                    break;
                case 1:
                    parent->right=NULL;
                    break;
            }
            curr = NULL;
        }


        else if(!curr->left && curr->right){
            node * del=curr;
            curr = curr->right;
            del = NULL;
        }

        else if (!curr->right){
            node * del=curr;
            curr = curr->left;
            del = NULL;
        }

        else{
            node * n = curr->left->find_max();
            curr->key = n->key;
            curr->value = n->value;
            remove(curr->key, curr->left, curr, -1);
        }
    }
}

template<class K, class V>
void mapp<K,V>::remove(K _key){
    root->remove(_key, root, NULL, 0);
}

template<class K, class V>
node<K,V> * node<K, V>::find_max(){
    if(left != NULL)
        return left->find_max();

    return this;
}
