#include <bits/stdc++.h>

using namespace std;
const int M = 5e4 + 10;
int Elsie[M];
int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fin.open("cardgame.in"), fout.open("cardgame.out");
    int n;
    fin >> n;
    set<int> Bessie;
    vector<bool> Cars(2 * n + 1);
    for (int i = 0; i < n; i++)
    {
        fin >> Elsie[i];
        Cars[Elsie[i]] = 1;
    }
    sort(Elsie, Elsie + n / 2 - 1);
    sort(Elsie + n / 2, Elsie + n, greater<int>());
    for (int i = 1; i <= 2 * n; i++)
        if (!Cars[i])
            Bessie.insert(i);

    int res = 0;
    for (int i = n - 1; i >= n / 2; i--)
    {
        if (*(Bessie.begin()) < Elsie[i])
        {
            res++;
            Bessie.erase(Bessie.begin());
        }
    }
    for (int i = 0; i < n / 2; i++)
    {
        auto it = upper_bound(Bessie.begin(), Bessie.end(), Elsie[i]);
        if (it != Bessie.end())
        {
            res++;
            Bessie.erase(it);
        }
    }
    fout << res;
    fin.close(), fout.close();
    return 0;
}