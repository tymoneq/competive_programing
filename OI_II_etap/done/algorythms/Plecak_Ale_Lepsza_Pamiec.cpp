#include <bits/stdc++.h>

using namespace std;

int main()
{
    constexpr int INF = -1e8;
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> Przedmioty(n);

    // wczytywanie first - > waga second - > wartość
    for (auto &przedmiot : Przedmioty)
        cin >> przedmiot.first >> przedmiot.second;

    // Ustawiamy wszystkie wartości na -INF
    vector<int> plecak(w + 1, INF);
    // Ustawiamy stan 0 na 0
    plecak[0] = 0;

    for (int i = 0; i < n; i++)
        for (int waga = w; waga >= Przedmioty[i].first; waga--)
            plecak[waga] = max(plecak[waga], plecak[waga - Przedmioty[i].first] + Przedmioty[i].second);

    int mx = 0;
    for (int i = 0; i <= w; i++)
        mx = max(plecak[i], mx);
    cout << mx << "\n";
    return 0;
}