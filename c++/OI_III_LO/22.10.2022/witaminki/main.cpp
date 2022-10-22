#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, parz = 0, nie_par = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        if (a % 2 == 0)
            parz += 1;
        else
            nie_par += 1;
    }
    unsigned long long wynik = 0;
    if (nie_par == 0)
        wynik = pow(2, parz) - 1;
    else
    {
        if (parz == 0)
        {
            wynik = pow(2, nie_par - 1) - 1;
        }
        else
            wynik = parz * nie_par + parz + nie_par - 1;
    }
    cout << wynik % 1000003;
    return 0;
}