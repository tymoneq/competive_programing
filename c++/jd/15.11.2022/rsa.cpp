#include <bits/stdc++.h>

using namespace std;
vector<int> Sito(int n)
{
    vector<int> sito;
    vector<bool> Checked(n + 1, 0);
    for (int i = 2; i * i <= n; i++)
        if (!Checked[i])
            for (int j = i * i; j <= n; j += i)
                Checked[j] = 1;

    for (int i = 2; i <= n; i++)
        if (Checked[i] == 0)
            sito.push_back(i);
    return sito;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int p, q, e, fi, d, l, n;
    cin >> n >> e >> l;

    return 0;
}