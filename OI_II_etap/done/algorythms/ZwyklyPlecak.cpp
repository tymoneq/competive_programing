#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> Przedmioty(n);

    // wczytywanie first - > waga second - > wartość
    for (auto &przedmiot : Przedmioty)
        cin >> przedmiot.first >> przedmiot.second;

    // tworzymy 2 wymiarową tablicę o wymiarach n+1 na w+1 gdzie n-> ilość przedmiotów a w-> max waga plecaka
    vector<vector<int>> plecak(n + 1, vector<int>(w + 1, 0));

    for (int i = 1; i <= n; i++)
        for (int waga = 0; waga <= w; waga++)
        {
            // sprawdzamy czy waga przedmiotu nie jest większa od aktualnie rozpatrywanej wagi
            if (Przedmioty[i - 1].first > waga)
                continue;

            // liczymy stan dla plecak[i][waga] patrząć co da nam lepszy wynik
            // robimy to poprzez branie max z aktualnej wartości
            // i wartości którą wcześniej wyliczyliśmy dla ilości przedmiotów mniejszej o 1 i wadze mniejszej o wagę aktualnego przedmiotu
            plecak[i][waga] = max(plecak[i][waga], plecak[i - 1][waga - Przedmioty[i - 1].first] + Przedmioty[i - 1].second);
        }

    cout << plecak[n][w] << "\n";
    return 0;
}