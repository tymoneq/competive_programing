#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Używamy long long, ponieważ rozmiary naleśników mogą dochodzić do 10^12
typedef long long ll;

// Funkcja pomocnicza do obliczania wyniku dla x wybranych pełnych stosów
ll eval(ll x, ll m, ll k_left, int banned_pos, const vector<ll>& pref_P, const vector<ll>& pref_B) {
    ll sum_b = 0;
    if (x > 0) {
        // Jeśli omijamy konkretny stos (bo właśnie go 'nadgryzamy') i jest on w naszym zasięgu:
        if (banned_pos != -1 && banned_pos < x) {
            sum_b = pref_B[x + 1] - (pref_B[banned_pos + 1] - pref_B[banned_pos]);
        } else {
            sum_b = pref_B[x];
        }
    }
    
    ll p_needed = k_left - x * m;
    // Sprawdzenie, czy mamy wystarczająco dużo pojedynczych naleśników
    if (p_needed < 0 || p_needed >= pref_P.size()) return -1; 
    
    return sum_b + pref_P[p_needed];
}

int main() {
    // Optymalizacja operacji wejścia/wyjścia
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    vector<ll> P; // Wolna pula naleśników ze stosów "Malejących"
    vector<vector<ll>> inc_stacks; // Zbiór stosów "Rosnących"
    vector<pair<ll, int>> B_pairs; // Sumy całych stosów rosnących i ich oryginalne indeksy

    for (int i = 0; i < n; ++i) {
        vector<ll> st(m);
        for (int j = 0; j < m; ++j) {
            cin >> st[j];
        }
        // Jeśli górny naleśnik jest większy-równy dolnemu (Malejący stos)
        if (m == 1 || st[0] >= st[m - 1]) {
            for (ll val : st) P.push_back(val);
        } else {
            // Rosnący stos - traktujemy go na razie jako nierozerwalny blok
            ll sum = 0;
            for (ll val : st) sum += val;
            int id = inc_stacks.size();
            inc_stacks.push_back(st);
            B_pairs.push_back({sum, id});
        }
    }

    // Sortowanie malejące pojedynczych naleśników i tworzenie sum prefiksowych
    sort(P.rbegin(), P.rend());
    vector<ll> pref_P(P.size() + 1, 0);
    for (size_t i = 0; i < P.size(); ++i) {
        pref_P[i + 1] = pref_P[i] + P[i];
    }

    // Sortowanie bloków rosnących od najbardziej wartościowych
    sort(B_pairs.rbegin(), B_pairs.rend());
    vector<ll> pref_B(B_pairs.size() + 1, 0);
    vector<int> pos_in_B(inc_stacks.size(), -1);
    
    for (size_t i = 0; i < B_pairs.size(); ++i) {
        pref_B[i + 1] = pref_B[i] + B_pairs[i].first;
        pos_in_B[B_pairs[i].second] = i; // Zapisujemy nową pozycję dla szybkiego dostępu
    }

    // Wyszukiwanie Ternarne zdefiniowane jako funkcja lambda
    auto solve_full = [&](ll k_left, int banned_pos) -> ll {
        ll total_valid_B = B_pairs.size();
        if (banned_pos != -1 && total_valid_B > 0) total_valid_B--;
        
        ll r = min((ll)total_valid_B, k_left / m);
        ll l = 0;
        ll p_size = (ll)pref_P.size() - 1;
        
        // Zabezpieczenie przed brakiem wystarczającej liczby elementów ogółem
        if (k_left > p_size + r * m) return -1;
        
        // Wyliczamy minimalną liczbę bloków, które MUSIMY wziąć
        ll min_x = 0;
        if (k_left > p_size) {
            min_x = (k_left - p_size + m - 1) / m;
        }
        l = max(l, min_x);
        
        if (l > r) return -1;

        // Główna pętla Wyszukiwania Ternarnego na funkcji wklęsłej
        while (r - l > 2) {
            ll m1 = l + (r - l) / 3;
            ll m2 = r - (r - l) / 3;
            ll v1 = eval(m1, m, k_left, banned_pos, pref_P, pref_B);
            ll v2 = eval(m2, m, k_left, banned_pos, pref_P, pref_B);
            
            if (v1 < v2) l = m1;
            else r = m2;
        }
        
        // Sprawdzenie ścisłego optimum z pozostałego, wąskiego przedziału
        ll best = -1;
        for (ll i = l; i <= r; ++i) {
            best = max(best, eval(i, m, k_left, banned_pos, pref_P, pref_B));
        }
        return best;
    };

    // KROK 1: Obliczamy maksimum dla scenariusza bez naruszania (częściowego) żadnego stosu
    ll ans = solve_full(k, -1);

    // KROK 2: Testujemy wariant "nadgryzienia" dokładnie jednego ze stosów rosnących
    for (size_t i = 0; i < inc_stacks.size(); ++i) {
        int banned_pos = pos_in_B[i];
        ll current_prefix_sum = 0;
        for (int c = 1; c < m; ++c) {
            current_prefix_sum += inc_stacks[i][c - 1]; // Zjadamy 'c' górnych elementów
            if (k >= c) {
                ll sub_ans = solve_full(k - c, banned_pos);
                if (sub_ans != -1) {
                    ans = max(ans, current_prefix_sum + sub_ans);
                }
            }
        }
    }

    // Wypisanie wyniku
    cout << ans << "\n";

    return 0;
}