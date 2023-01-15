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
    for (int i = 0; i < n; i++)
        fin >> Cows[i];
    double res = (Cows[0] + Cows[n - 1]) / 2, tmp;
    double sum = Cows[0] + Cows[n - 1];
    double num = 2;
    int l = 1, r = n - 2;
    while (l < r)
    {
        if (Cows[l] > Cows[r])
        {
            num++;
            sum += Cows[r];
            tmp = sum / num;
            res = min(res, tmp);
            r--;
        }
        else
        {
            num++;
            sum += Cows[l];
            tmp = sum / num;
            res = min(res, tmp);
            l++;
        }
    }
    fout << fixed << setprecision(3) << res;
    fin.close(), fout.close();
    return 0;
}