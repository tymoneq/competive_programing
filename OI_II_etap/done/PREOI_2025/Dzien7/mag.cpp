#include "maglib.h"
#include <bits/stdc++.h>

using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

void wyczaruj_odpowiedz(int n)
{
    const char Zwykle = 'R';
    const char Magiczne = 'T';

    vector<char> Ans(n);

    Ans[0] = Magiczne;

    FOR(i, n, 1)
    {
        vector<int> Q = {0, i};
        auto ile = zapytaj_maszyne(Q);

        if (ile[0] == 1)
            Ans[i] = Zwykle;
        else
            Ans[i] = Magiczne;
    }

    odpowiedz(Ans);
}