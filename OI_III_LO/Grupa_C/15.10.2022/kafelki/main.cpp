#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    // cin.tie(0);
    cout.tie(0);

    string a;
    cin >> a;
    int b = a.size() + 1;
    int tab[b]{0};

    tab[b - 1] = 8;
    for (int i = b - 2; i >= 0; i--)
    {
        int temp = a[i] - 48;
        temp *= 3;
        if (temp >= 10)
        {
            int dz = temp % 10;
            temp /= 10;
            if (tab[i + 1] + dz >= 10)
            {
                tab[i + 1] += dz;
                int mod = tab[i + 1] % 10;
                int dz_2 = tab[i + 1] / 10;
                tab[i + 1] = mod;
                tab[i] += dz_2;
            }
            else
            {
                tab[i + 1] += dz;
            }

            tab[i] += temp;
        }
        else
        {

            tab[i + 1] += temp;
            if (tab[i + 1] >= 10)
            {
                int mod = tab[i + 1] % 10;
                int div = tab[i + 1] / 10;
                tab[i + 1] = mod;
                tab[i] += div;
            }
        }
    }
    bool first = true;
    for (int i = 0; i < b; i++)
    {
        if (tab[i] == 0 && first)
            continue;
        else
        {
            cout << tab[i];
            first = false;
        }
    }
    return 0;
}