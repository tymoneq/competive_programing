#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, wynik = 1;
    cin >> n;
    vector<vector<char>> V(n);
    string alf;
    for (int i = 0; i < n; i++)
    {
        cin >> alf;
        V[i].push_back(alf[0]);
        V[i].push_back(alf[1]);
        V[i].push_back(alf[2]);
    }
    if (n == 1)
        wynik = 3;
    else if (n % 2 == 0)
    {
        vector<int> res(n / 2);
        for (int k = 0; k < n / 2; k++)
        {
            int result = 0;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (V[k][i] == V[n - k - 1][j])
                    {
                        result += 1;
                        break;
                    }
                }
            }
            res[k] = result;
        }
        for (auto el : res)
        {
            wynik = el * wynik;
            wynik %= 1000000009;
        }
    }
    else
    {
        vector<int> res(n / 2);
        for (int k = 0; k < n / 2; k++)
        {
            int result = 0;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (V[k][i] == V[n - k - 1][j])
                    {
                        result += 1;
                        break;
                    }
                }
            }
            res[k] = result;
        }
        for (auto el : res)
        {
            wynik = el * wynik;
            wynik %= 1000000009;
        }
        wynik *= 3;
    }

    cout << wynik % 1000000009;
    return 0;
}