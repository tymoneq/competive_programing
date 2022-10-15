#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, wynik = 0;
    cin >> n;
    int tab[n]{0};

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        tab[i] = a;
    }
    if (n == 1)
        cout << 0 << "\n";
    else if (n == 2)
    {
        if (tab[0] > tab[1])
            cout << 0 << "\n";
        else
            cout << 1 << "\n";
    }
    else
    {
        for (int i = 2; i < n; i++)
        {
            int a, b, c;
            a = tab[i];
            b = tab[i - 1];
            c = tab[i - 2];
            if (b > a)
            {
                if (c < a)
                {
                    tab[i] = c;
                    tab[i - 1] = a;
                    tab[i - 2] = b;
                    wynik += 1;
                }
            }
            else if (b < a)
            {
                if (c < a)
                {
                    tab[i - 2] = a;
                    tab[i - 1] = c;
                    tab[i] = b;
                    if (b > c)
                        wynik += 1;
                    
                }
                else if (c > a)
                {
                    tab[i] = b;
                    tab[i - 1] = a;
                    wynik++;
                }
            }
        }
        cout << wynik;
    }

    return 0;
}