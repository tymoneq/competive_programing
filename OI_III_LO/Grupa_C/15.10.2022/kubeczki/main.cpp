#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b, c, x, y, wynik = 0;
        bool a_dif_b = true, a_dif_c = true, c_dif_b = true;
        cin >> a >> b >> c >> x >> y;
        int zakres = y + 1 - x;
        if (a == b && b == c)
        {
            cout << zakres / a << "\n";
            continue;
        }
        if (max(a, b) % min(a, b) == 0)
            a_dif_b = false;
        if (max(a, c) % min(a, c) == 0)
            a_dif_c = false;
        if (max(c, b) % min(c, b) == 0)
            c_dif_b = false;
        if (!a_dif_c)
        {
            wynik += zakres / a;
            wynik += zakres / b;
            wynik -= zakres / (a * b);
        }

        else if (!a_dif_b)
        {
            wynik += zakres / a;
            wynik += zakres / c;
            wynik -= zakres / (a * c);
        }
        else if (!c_dif_b)
        {
            wynik += zakres / c;
            wynik += zakres / b;
            wynik -= zakres / (c * b);
        }
        else
        {
            wynik += zakres / a;
            wynik += zakres / b;
            wynik += zakres / c;
            wynik -= zakres / (a * b);
            wynik -= zakres / (a * c);
            wynik -= zakres / (c * b);
        }
        cout << wynik << "\n";
    }

    return 0;
}