#include <bits/stdc++.h>

using namespace std;
const int M = 1e5 + 10;
bool Tab[M];
ifstream fin;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int pot = 1,num,res=0;
    fin.open("liczby.txt");
    while (pot <= M)
    {
        Tab[pot] = 1;
        pot *= 3;
    }
    for (int i = 0; i <= 500; i++)
    {
        fin>> num;
        if(Tab[num])
            res++;
    }
    cout<< res;
    fin.close();
    return 0;
}