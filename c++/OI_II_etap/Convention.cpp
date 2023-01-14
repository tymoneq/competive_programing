#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> Cows(n);
    for (int i = 0; i < n; i++)
        cin >> Cows[i];
    sort(Cows.begin(), Cows.end());
    fin.close(), fout.close();
    return 0;
}