#include <bits/stdc++.h>
using namespace std;
vector<int> Cows;
int n, c, m;
bool validate(int v)
{
    int bus = 0, cow = 0, lcow = 0;
    while (cow < n)
    {
        if (cow == lcow)
            bus++;
        if (Cows[cow] - Cows[lcow] > v)
            lcow = cow;
        else if (cow - lcow + 1 == c)
            lcow = ++cow;
        else
            cow++;
    }
    return bus <= m;
}
int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fin.open("convention.in"), fout.open("convention.out");
    fin >> n >> m >> c;
    Cows.resize(n);
    for (int i = 0; i < n; i++)
        fin >> Cows[i];
    sort(Cows.begin(), Cows.end());
    int lo = 0, hi = Cows[n - 1] - Cows[0], mid;
    while (lo < hi)
    {
        mid = lo + (hi - lo) / 2;
        if (validate(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    fout << lo;
    fin.close(), fout.close();
    return 0;
}