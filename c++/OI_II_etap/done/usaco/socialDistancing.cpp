#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<long long, long long>> Grass;
int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fin.open("socdist.in"), fout.open("socdist.out");
    fin >> n >> m;
    Grass.resize(m);
    for (int i = 0; i < m; i++)
        fin >> Grass[i].first >> Grass[i].second;

    sort(Grass.begin(), Grass.end());
    long long lo = 0, mid, hi = Grass[m - 1].second - Grass[0].first + 1, count, interval_count, current;
    while (lo < hi)
    {
        count = 1, interval_count = 0, current = Grass[0].first;
        mid = lo + (hi - lo+1) / 2;
        while ((current + mid) < Grass[m - 1].second)
        {
            while (current + mid > Grass[interval_count].second)
                interval_count++;

            current = max(Grass[interval_count].first, current + mid);
            count++;
            if (count == n)
                break;
        }

        if (count >= n)
            lo = mid;
        else
            hi = mid - 1;
    }
    fout << lo;
    return 0;
}