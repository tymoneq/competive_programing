#include <bits/stdc++.h>

using namespace std;
int p()
{
    return 0 + rand() % 2;
}
int main()
{
    int z, n;
    cin >> z;
    //cout << 500 << "\n";
    srand(z);
    for (int i = 0; i < 10000; i++)
    {
        if(p ==1)
            cout <<"A";
        else
        cout << "B";
    }
}
