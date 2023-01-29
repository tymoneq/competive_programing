#include <bits/stdc++.h>
using namespace std;
constexpr int M = 1e5+7;
int Pref_sum[M];
bool Not_working[M];
ifstream fin;
ofstream fout;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, b, a, x;
    fin.open("maxcross.in"), fout.open("maxcross.out");
    fin >> n >> k >> b;
    for (int i = 1; i <= b; i++)
    {
        fin >> a;
        Not_working[a] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        x = 0;
        if (Not_working[i])
            x = 1;
        Pref_sum[i] = Pref_sum[i - 1] + x;
    }
    int res = Pref_sum[k];
    for (int i = 1; i <= n-k; i++)
        res = min(res, Pref_sum[k + i] - Pref_sum[i]);

    fout << res;
    return 0;
}