#include "z2.h"


int main()
{
    mapp<int, string> m;

    m.add(1, "jeden");
    m.add(2, "dwa");
    m.add(0, "zero");
    m.remove(1);
    m.print();
}
