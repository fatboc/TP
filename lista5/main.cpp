#include "l5.h"

int main()
{
    param p(1, 10, 1);

    p.setv(0,0,0);
    p.setr(0,0,100);

    p.setpoints();

    return 0;

}
