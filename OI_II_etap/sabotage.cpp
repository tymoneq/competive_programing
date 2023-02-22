#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fin.open("sabotage.in"), fout.open("sabotage.out");
    int n;
    fin >> n;
    vector<double> Cows(n);
    double sum = 0, tmp;
    for (int i = 0; i < n; i++)
    {
        fin >> Cows[i];
        sum += Cows[i];
    }
    double res = sum / n;
    int l = 1, r = n - 2, mid;
    int curent, mx;
    for (int j = 1; j <= n - 2; j++)
    {
        mid = j;
        curent = 0, mx = 0;
        for (int i = 1; i <= mid; i++)
            curent += Cows[i];
        mx = curent;
        for (int i = mid + 1; i < n - 1; i++)
        {
            curent -= Cows[i - mid];
            curent += Cows[i];
            mx = max(mx, curent);
        }
        tmp = (sum - mx) / (n - mid);
        res = min(tmp, res);
    }
    if (n == 3)

        res = (sum - Cows[1]) / 2;
    
    fout << fixed << setprecision(3) << res;
    fin.close(), fout.close();
    return 0;
}