#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> ListaKandydatow;
int P[11] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int n;
inline void generuj(int j, int max_pot, int kand, int l_dzielnikow)
{
    ListaKandydatow.push_back({kand, l_dzielnikow});
    for (int i = 1; i <= max_pot; i++)
    {
        if (P[j] > (n / kand))
            return;
        kand *= P[j];
        generuj(j + 1, i, kand, l_dzielnikow * (i + 1));
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    generuj(1, 31, 1, 1);
    sort(ListaKandydatow.begin(), ListaKandydatow.end());

    int ans = 0, l_dzielnikow = 0;
    for (auto &a : ListaKandydatow)
        if (a.first > ans && a.second > l_dzielnikow)
        {
            ans = a.first;
            l_dzielnikow = a.second;
        }

    cout << ans << "\n";

    return 0;
}