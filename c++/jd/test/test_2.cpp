#include <bits/stdc++.h>

using namespace std;
int Silnia[10];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream fin;
    int a,A,res=0,tmp,sum=0;
    fin.open("przyklad.txt");
    Silnia[0] = Silnia[1] = 1;
    for (int i = 2; i < 10; i++)
        Silnia[i] = Silnia[i - 1] * i;

    for (int i = 0; i < 500; i++)
    {
        sum=0;
        fin>> a;
        A= a;
        while (a>0)
        {
            tmp = a%10;
            sum+= Silnia[tmp];
            a/=10;
        }
        if(sum == A)
            cout << A <<"\n";
    }
    fin.close();
    return 0;
}