#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string T, num;
    cin >> num >> T;
    long long wynik = 0;
    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] == '?')
            continue;
        else
            wynik += num[i] - 48;
    }
    for (int i = 0; i < 10; i++)
    {
        if ((wynik + i) % 9 == 0)
        {
            cout << i;
            break;
        }
    }

    return 0;
}