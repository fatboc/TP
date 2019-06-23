#include "l5.h"

int main()
{
    /*string name;

    cout << "Podaj nazwe pliku z danymi do obliczen, badz wcisnij 0, by wpisac je recznie:" << endl;
    cin >> name;

    if(name=="0"){
        param p;
        p.get_init_val();
    }

    else{

    }*/
//    param p(1, 10, 0.1);
//
//    p.setv(50,0,50);
//    p.setr(0,0,100);
//    p.setw(1,5,0);
//    p.setk(0.05);
//    p.setm(1.0);

    param p;

    p.set_init_val();;

    p.setpoints();

    p.fprint();

    return 0;

}
