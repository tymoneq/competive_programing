#include <bits/stdc++.h>
using namespace std;

int main()
{
    const int mod =10000;
    int z, n, m, a, b;
    cin >> z;
    srand(z);
    n = rand() % mod;
    n++;
    m = rand() % mod;
    m++;
    cout << n << " " << m << "\n";
    for (int i = 0; i < n; i++)
    {
        a = rand() % 10;
        a++;
        cout << a << " ";
    }
    for (int i = 0; i < m; i++)
    {
        a = rand() % 6000;
        a++;
        b = rand() % 4000;
        b += a;
        cout << a << ' ' << b << "\n";
    }
    return 0;
}