#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fin.open("outofplace.in"), fout.open("outofplace.out");
    int n;
    fin >> n;
    vector<int> Cows(n), Sorted(n);

    for (int i = 0; i < n; i++)
    {
        fin >> Cows[i];
        Sorted[i] = Cows[i];
    }
    int res = 0;
    sort(Sorted.begin(), Sorted.end());
    for (int i = 0; i < n; i++)
        if (Sorted[i] != Cows[i])
            res++;
    fout << res - 1;
    fin.close(), fout.close();
    return 0;
}