#include <bits/stdc++.h>
using namespace std;
vector<int> Hay;
int n, k;
bool validate(int v)
{
    int cows = 0;
    int range = -1;
    for (int i = 0; i < n; i++)
        if (Hay[i] > range)
        {
            range = Hay[i] + 2 * v;
            cows++;
        }
    return cows <= k;
}
int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fin.open("angry.in"), fout.open("angry.out");
    fin >> n >> k;
    Hay.resize(n);
    for (int i = 0; i < n; i++)
        fin >> Hay[i];
    sort(Hay.begin(), Hay.end());
    int lo = 0, hi = (Hay[n - 1] - Hay[0]) / 2, mid = 0;
    while (lo < hi)
    {
        mid = lo + (hi - lo) / 2;
        if (validate(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    fout << lo;
    fout.close(), fin.close();
    return 0;
}