#include "VectorInt.h"

int main()
{
    VectorInt v(5);

    std::cout << v.size() << std::endl << v.capacity() << std::endl;

    for (int i=0; i<3; i++)
        v.pushBack(i+1);

    std::cout << v.size() << std::endl << v.capacity() << std::endl;

    v.shrinkToFit();
    std::cout << v.size() << std::endl << v.capacity() << std::endl;

    for (int i=3; i<7; i++)
        v.pushBack(i+1);

    std::cout << v.size() << std::endl << v.capacity() << std::endl << v << std::endl;

    v.insert(0, 0);
    std::cout << v.at(0) << std::endl;
    v.popBack();
    std::cout << v << std::endl;

    v.clear();
    std::cout << v.size() << std::endl << v.capacity() << std::endl << v << std::endl;

    v.pushBack(11);
    std::cout << v << std::endl;

    return 0;
}
