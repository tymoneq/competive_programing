#include <bits/stdc++.h>
// kod z omówienia 
using namespace std;

int main()
{
    int n, m, operacje = 0;
    cin >> n >> m;
    bool running = true;
    while (running)
    {
        if (n > m)
        {
            int wynik = m - n;
            cout << -wynik;
            running = false;
        }
        else if (m == n)
        {
            cout << operacje;
            running = false;
        }
        else if (m % 2 == 0)
        {
            m = m / 2;
            operacje += 1;
        }
        else if (m % 2 == 1)
        {
            m += 1;
            operacje += 1;
        }
    }

    return 0;
}