#include <bits/stdc++.h>

using namespace std;
int Mod = 1;
inline bool cmp(int &lhs, int &rhs) { return (lhs % Mod) > (rhs % Mod); }
int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fin.open("berries.in"), fout.open("berries.out");
    int n, k;
    fin >> n >> k;
    vector<int> Trees(n);
    int MAXD = 0;
    for (int i = 0; i < n; i++)
    {
        fin >> Trees[i];
        MAXD = max(MAXD, Trees[i]);
    }
    int mx = 0, amount = 0;
    for (int i = 1; i <= MAXD; i++)
    {
        amount = 0;
        for (int j = 0; j < n; j++)
            amount += Trees[j] / i;
        if (amount < k / 2)
            continue;
        if (amount >= k)
        {
            mx = max(mx, (k / 2) * i);
            continue;
        }

        Mod = i;
        sort(Trees.begin(), Trees.end(), cmp);
        int cur = (amount - k / 2) * i;
        for (int j = 0; j < n && j + amount < k; j++)
            cur += Trees[j] % i;
        mx = max(mx, cur);
    }
    fout << mx;
    fin.close(), fout.close();
    return 0;
}