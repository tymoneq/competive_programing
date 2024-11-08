#include <bits/stdc++.h>

using namespace std;

typedef long long ull;

constexpr int N = 2e5 + 10;
struct domino
{
    ull N1, N2, H1, H2;
};
vector<pair<ull, ull>> PoczantkoweDomino;
domino Wykorzystane[N];
domino D;

set<pair<ull, int>> S; // first - > ile potrzeba małych second - > index w Wykorzystane

inline void upt(int &l, ull &current_max)
{

    current_max -= (Wykorzystane[l].N1 + Wykorzystane[l].N2 + 1);

    D.N1 += Wykorzystane[l].N1;
    D.N2 += Wykorzystane[l].N2;
    Wykorzystane[l].N1 = Wykorzystane[l].N2 = 0;

    vector<set<std::pair<ull, int>>::iterator> A;
    for (auto it = S.begin(); it != S.end(); it++)
    {
        if (D.N2 >= it->first)
        {
            current_max += it->first - 1;
            Wykorzystane[it->second].N1--;
            Wykorzystane[it->second].N2 += it->first;
            D.N1++;
            D.N2 -= it->first;

            A.push_back(it);
        }
        else
            break;
    }

    for (auto el : A)
        S.erase(el);

    l++;
}
inline void upt2(int &r, ull &current_max, ull &current_range, ull n1, ull n2)
{
    D.N1 -= n1;
    D.N2 -= n2;
    current_max += n1 + 1 + n2;
    Wykorzystane[r].N1 = n1;
    Wykorzystane[r].N2 = n2;
    r++;
    current_range = max(PoczantkoweDomino[r].second + PoczantkoweDomino[r].first, current_range + n1 * D.H1 + n2 * D.H2);
}
inline void upt3(int &r, ull &current_max, ull &current_range, ull n1, ull n2)
{
    D.N1 -= n1;
    D.N2 -= n2;
    current_max += n1 + 1 + n2;
    Wykorzystane[r].N1 = n1;
    Wykorzystane[r].N2 = n2;
    r++;
    current_range = min(PoczantkoweDomino[r].first - PoczantkoweDomino[r].second, current_range - n1 * D.H1 - n2 * D.H2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    ull res = 0;

    cin >> n;

    PoczantkoweDomino.resize(n);

    for (auto &el : PoczantkoweDomino)
        cin >> el.first >> el.second;

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
            current_range = max(PoczantkoweDomino[r].second + PoczantkoweDomino[r].first, current_range);
        }
        else
        {
            ull needed_range = PoczantkoweDomino[r + 1].first - current_range;

            ull needed_range_after_H1 = needed_range / D.H1;

            if (needed_range_after_H1 * D.H1 == needed_range && needed_range_after_H1 <= D.N1)
                upt2(r, current_max, current_range, needed_range_after_H1, 0);

            else if (needed_range_after_H1 * D.H1 < needed_range && needed_range_after_H1 <= D.N1)
            {

                ull neededN2 = (needed_range - (needed_range_after_H1 * D.H1)) / D.H2;

                if ((needed_range - (needed_range_after_H1 * D.H1)) % D.H2 != 0)
                    neededN2++;

                // wykorzystujemy małe
                if (neededN2 <= D.N2)
                    upt2(r, current_max, current_range, needed_range_after_H1, neededN2);

                // dokładamy kolejne duże
                else if (neededN2 > D.N2 && needed_range_after_H1 + 1 <= D.N1)
                {
                    S.insert({neededN2, r});
                    upt2(r, current_max, current_range, needed_range_after_H1 + 1, 0);
                }
                // nie da się dołożyć
                else
                    upt(l, current_max);
            }

            else if (needed_range_after_H1 > D.N1)
            {

                ull neededN2 = (needed_range - (D.N1 * D.H1)) / D.H2;

                if ((needed_range - (needed_range_after_H1 * D.H1)) % D.H2 != 0)
                    neededN2++;

                // wykorzystujemy małe
                if (neededN2 <= D.N2)
                    upt2(r, current_max, current_range, D.N1, neededN2);

                // nie da się dołożyć
                else
                    upt(l, current_max);
            }
            else
                upt(l, current_max);
        }
        res = max(res, current_max + D.N1 + D.N2);
    }

    for (int i = 0; i < n; i++)
    {
        D.N1 += Wykorzystane[i].N1;
        D.N2 += Wykorzystane[i].N2;
        Wykorzystane[i].N1 = Wykorzystane[i].N2 = 0;
    }

    l = 0, r = -1;
    current_max = 0, current_range = 0;
    S.clear();
    sort(PoczantkoweDomino.begin(), PoczantkoweDomino.end(), greater<pair<ull, ull>>());
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
            current_range = PoczantkoweDomino[r].first - PoczantkoweDomino[r].second;
        }
        else if (PoczantkoweDomino[r + 1].first >= current_range)
        {
            current_max++;
            r++;
            current_range = min(PoczantkoweDomino[r].first - PoczantkoweDomino[r].second, current_range);
        }
        else
        {
            ull needed_range = abs(PoczantkoweDomino[r + 1].first - current_range);

            ull needed_range_after_H1 = needed_range / D.H1;

            if (needed_range_after_H1 * D.H1 == needed_range && needed_range_after_H1 <= D.N1)
                upt3(r, current_max, current_range, needed_range_after_H1, 0);

            else if (needed_range_after_H1 * D.H1 < needed_range && needed_range_after_H1 <= D.N1)
            {

                ull neededN2 = abs(needed_range - (needed_range_after_H1 * D.H1)) / D.H2;

                if ((needed_range - (needed_range_after_H1 * D.H1)) % D.H2 != 0)
                    neededN2++;

                // wykorzystujemy małe
                if (neededN2 <= D.N2)
                    upt3(r, current_max, current_range, needed_range_after_H1, neededN2);

                // dokładamy kolejne duże
                else if (neededN2 > D.N2 && needed_range_after_H1 + 1 <= D.N1)
                {
                    S.insert({neededN2, r});
                    upt3(r, current_max, current_range, needed_range_after_H1 + 1, 0);
                }
                // nie da się dołożyć
                else
                    upt(l, current_max);
            }

            else if (needed_range_after_H1 > D.N1)
            {

                ull neededN2 = abs(needed_range - (D.N1 * D.H1)) / D.H2;

                if ((needed_range - (needed_range_after_H1 * D.H1)) % D.H2 != 0)
                    neededN2++;

                // wykorzystujemy małe
                if (neededN2 <= D.N2)
                    upt3(r, current_max, current_range, D.N1, neededN2);

                // nie da się dołożyć
                else
                    upt(l, current_max);
            }
            else
                upt(l, current_max);
        }
        res = max(res, current_max + D.N1 + D.N2);
    }

    cout << res << "\n";
    return 0;
}