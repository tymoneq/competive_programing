#include <bits/stdc++.h>

using namespace std;
constexpr int M = 1010;
struct liarsAndTruthTellers
{
    int x, y, truth;
};
vector<int> Graph[M];
int TruthTellers[M];
vector<liarsAndTruthTellers> Cows;
bool valid(int val)
{
    for (int i = 0; i < val; i++)
    {
        Graph[Cows[i].x].clear();
        TruthTellers[Cows[i].y] = -1;
        TruthTellers[Cows[i].x] = -1;
    }
    for (int i = 0; i < val; i++)
    {
        Graph[Cows[i].x].push_back(Cows[i].y);
        if (TruthTellers[Cows[i].x] != 0)
        {
            if (TruthTellers[Cows[i].y] == -1)
            {
                TruthTellers[Cows[i].y] = Cows[i].truth;
                if (TruthTellers[Cows[i].y] == 0)
                    for (int w : Graph[Cows[i].y])
                        if (TruthTellers[w] != -1)
                            return 0;
            }
            else if (Cows[i].truth != TruthTellers[Cows[i].y])
                return 0;
        }
        else
        {
            if (TruthTellers[Cows[i].y] == -1)
            {
                TruthTellers[Cows[i].y] = Cows[i].truth;
                TruthTellers[Cows[i].y] ^= 1;
                if (TruthTellers[Cows[i].y] == 0)
                    for (int w : Graph[Cows[i].y])
                        if (TruthTellers[w] != -1)
                            return 0;
            }
            else if (Cows[i].truth != TruthTellers[Cows[i].y])
                return 0;
        }
    }
    return 1;
}

int main()
{
    // freopen("truth.in", "r", stdin);
    // freopen("truth.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    Cows.resize(m);
    char z;
    for (int i = 0; i < m; i++)
    {
        cin >> Cows[i].x >> Cows[i].y >> z;
        if (z == 'T')
            Cows[i].truth = 1;
        else
            Cows[i].truth = 0;
    }
    int lo = 1, hi = m, mid, res = 0;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (valid(mid))
        {
            lo = mid + 1;
            res = mid;
        }
        else
            hi = mid - 1;
    }

    cout << res;
    return 0;
}