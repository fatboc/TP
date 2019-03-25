#include <iostream>


using namespace std;

int main()
{
int n, i, m=0;

cout<<"Podaj liczbe naturalna: ";
cin>>n;

int**tab = new int*[n];
for(int i=0; i<=n; i++)
{
    tab[i]=new int[n];
}

cout<<"Liczba:  Dzielniki:";

for(int i=1; i<=n; i++)
{tab[0][0]=i;
cout<<endl<<tab[0][0]<<"        ";
m=1;
    for(int d=1; d<=i; d++)
    {
        if(i%d==0)
        {
            tab[i][m]=d;
            cout<<tab[i][m]<<" ";
            m=m+1;
        }
    }
}

for(i=0; i<n; i++)
    {
    delete tab[i];
    }
delete[] tab;




}
