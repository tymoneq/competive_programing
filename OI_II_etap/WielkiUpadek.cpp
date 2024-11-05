#include <bits/stdc++.h>

using namespace std;

typedef long long ull;

constexpr int N = 2e5 + 10;
struct domino
{
    ull N1, N2, H1, H2;
};

domino Wykorzystane[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    ull res = 0;

    cin >> n;
    vector<pair<ull, ull>> PoczantkoweDomino(n);

    for (auto &el : PoczantkoweDomino)
        cin >> el.first >> el.second;

    domino D;
    cin >> D.N1 >> D.H1 >> D.N2 >> D.H2;
    if (D.H2 > D.H1)
    {
        swap(D.H1, D.H2);
        swap(D.N1, D.N2);
    }

    int l = 0, r = -1;
    ull current_max = 0, current_range = 0;

    while (l < n)
    {
        if (r == n - 1)
        {
            res = max(res, current_max + D.N1 + D.N2);
            break;
        }

        if (r < l)
        {
            r++;
            current_max = 1;
            current_range = PoczantkoweDomino[r].first + PoczantkoweDomino[r].second;
        }
        else if (PoczantkoweDomino[r + 1].first <= current_range)
        {
            current_max++;
            r++;
            current_range = PoczantkoweDomino[r].second + PoczantkoweDomino[r].first;
        }
        else
        {
            ull needed_range = PoczantkoweDomino[r + 1].first - current_range;

            ull needed_range_after_H1 = needed_range / D.H1;

            if (needed_range_after_H1 * D.H1 == needed_range && needed_range_after_H1 <= D.N1)
            {

                D.N1 -= needed_range_after_H1;
                current_max += needed_range_after_H1 + 1;
                Wykorzystane[r].N1 = needed_range_after_H1;
                current_range = PoczantkoweDomino[r + 1].second + PoczantkoweDomino[r + 1].first;
                r++;
            }
            else if (needed_range_after_H1 * D.H1 < needed_range && needed_range_after_H1 <= D.N1)
            {

                ull neededN2 = (needed_range - (needed_range_after_H1 * D.H1)) / D.H2;

                if ((needed_range - (needed_range_after_H1 * D.H1)) % D.H2 != 0)
                    neededN2++;

                // wykorzystujemy małe
                if (neededN2 <= D.N2)
                {
                    D.N1 -= needed_range_after_H1;
                    D.N2 -= neededN2;
                    current_max += needed_range_after_H1 + 1 + neededN2;
                    Wykorzystane[r].N1 = needed_range_after_H1;
                    Wykorzystane[r].N2 = neededN2;
                    current_range = PoczantkoweDomino[r + 1].second + PoczantkoweDomino[r + 1].first;
                    r++;
                }
                // dokładamy kolejne duże
                else if (neededN2 > D.N2 && needed_range_after_H1 + 1 <= D.N1)
                {
                    D.N1 -= needed_range_after_H1 - 1;
                    current_max += needed_range_after_H1 + 1 + 1;
                    Wykorzystane[r].N1 = needed_range_after_H1 + 1;
                    current_range = PoczantkoweDomino[r + 1].second + PoczantkoweDomino[r + 1].first;
                    r++;
                }
                // nie da się dołożyć
                else
                {
                    res = max(res, current_max + D.N1 + D.N2);

                    current_max -= 1;
                    D.N1 += Wykorzystane[l].N1;
                    D.N2 += Wykorzystane[l].N2;
                    current_max -= (Wykorzystane[l].N1 + Wykorzystane[l].N2);
                    Wykorzystane[l].N1 = Wykorzystane[l].N2 = 0;
                    l++;
                }
            }

            else if (needed_range_after_H1 > D.N1)
            {

                ull neededN2 = (needed_range - (D.N1 * D.H1)) / D.H2;

                if ((needed_range - (needed_range_after_H1 * D.H1)) % D.H2 != 0)
                    neededN2++;

                // wykorzystujemy małe
                if (neededN2 <= D.N2)
                {

                    D.N2 -= neededN2;
                    current_max += D.N1 + 1 + neededN2;
                    Wykorzystane[r].N1 = D.N1;
                    Wykorzystane[r].N2 = neededN2;
                    D.N1 = 0;
                    current_range = PoczantkoweDomino[r + 1].second + PoczantkoweDomino[r + 1].first;
                    r++;
                }
                // nie da się dołożyć
                else
                {
                    res = max(res, current_max + D.N1 + D.N2);
                    current_max -= 1;
                    D.N1 += Wykorzystane[l].N1;
                    D.N2 += Wykorzystane[l].N2;
                    current_max -= (Wykorzystane[l].N1 + Wykorzystane[l].N2);
                    Wykorzystane[l].N1 = Wykorzystane[l].N2 = 0;
                    l++;
                }
            }
            else
            {
                res = max(res, current_max + D.N1 + D.N2);
                current_max -= 1;
                D.N1 += Wykorzystane[l].N1;
                D.N2 += Wykorzystane[l].N2;
                current_max -= (Wykorzystane[l].N1 + Wykorzystane[l].N2);
                Wykorzystane[l].N1 = Wykorzystane[l].N2 = 0;
                l++;
            }
        }
        res = max(res, current_max);
    }

    cout << res << "\n";
    return 0;
}