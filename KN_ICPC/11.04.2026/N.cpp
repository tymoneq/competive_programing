#include <bits/stdc++.h>
#include <ios>
#include <vector>

using namespace std;

inline void solve() {

    vector<int> Kosze(3);
    vector<int> Smieci(5);
    for (auto &g : Kosze)
        cin >> g;

    for (auto &g : Smieci)
        cin >> g;

    Kosze[0] -= Smieci[0];
    Kosze[1] -= Smieci[1];
    Kosze[2] -= Smieci[2];

    int mn = 1;

    for (auto g : Kosze) {
        mn = min(mn, g);
    }
    if (mn < 0) {
        cout << "NO\n";
        return;
    }

    int ile_4_mozna_dac_do_1 = min({Kosze[0], Smieci[3]});
    int ile_5_mozna_dac_do_2 = min({Kosze[1], Smieci[4]});

    Kosze[0] -= ile_4_mozna_dac_do_1;
    Kosze[1] -= ile_5_mozna_dac_do_2;

    Smieci[3] -= ile_4_mozna_dac_do_1;
    Smieci[4] -= ile_5_mozna_dac_do_2;

    Kosze[2] -= Smieci[3];
    Kosze[2] -= Smieci[4];

    mn = 1;

    for (auto g : Kosze) {
        mn = min(mn, g);
    }

    if (mn < 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}