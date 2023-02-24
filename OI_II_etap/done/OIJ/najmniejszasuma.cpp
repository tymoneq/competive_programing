#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
int main()
{
    // szybkie wczytywanie
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> Cyfry;
    ull res = 0, tmp, poweroften = 1;
    string s;
    int K, ind = 0, number_of_zero = 0;
    cin >> s >> K;
    for (char z : s)
    {
        Cyfry.push_back(z - '0');
        if (z - '0' == 0)
            number_of_zero++;
    }
    sort(Cyfry.begin(), Cyfry.end(), greater<int>());
    vector<vector<int>> Liczby(K);
    for (int i = 0; i < Cyfry.size() - number_of_zero; i++)
    {
        // sprawdzenie kiedy jest najlepszy moment na wstawienie zer
        /*
            dla przykładu 43091372
                           3
            Program znajdzie że 0 należy wstawić przed 1 do kolejnej liczby o indeksie ind

        */
        if (Cyfry.size() - i - K == number_of_zero)
            for (int j = 0; j < number_of_zero; j++)
            {
                Liczby[ind].push_back(0);
                ind++;
                if (ind == K)
                    ind = 0;
            }

        Liczby[ind].push_back(Cyfry[i]);
        ind++;
        if (ind == K)
            ind = 0;
    }
    // zliczanie wyniku
    for (int i = 0; i < K; i++)
    {
        tmp = 0;
        poweroften = 1;
        for (int num : Liczby[i])
        {
            tmp += num * poweroften;
            poweroften *= 10;
        }
        res += tmp;
    }

    cout << res;
    return 0;
}