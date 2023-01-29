#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int suma = 0, x_count = 0, suma_mod = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'X')
            x_count += 1;

        else
        {
            int temp = s[i];
            temp -= 48;
            suma += temp;
        }
    }
    if (x_count == 0)
    {
        cout << 0;
    }
    else
    {
        suma_mod = suma % 3;

        if (suma_mod == 0)
        {
            for (int i = 1; i < x_count; i++)
            {
                cout << "3";
            }
            cout << "4";
        }
        else if (suma_mod == 1)
        {
            for (int i = 0; i < x_count; i++)
            {
                cout << "3";
            }
        }
        else if (suma_mod == 2)
        {
            for (int i = 0; i < x_count; i++)
            {
                cout << "3";
            }
        }
    }
    return 0;
}