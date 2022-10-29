#include <bits/stdc++.h>

using namespace std;
vector<int> sito(int n)
{
    vector<int> v;
    vector<bool> table(n, 0);
    for (int i = 2; i * i <= n; i++)
    {
        if (table[i] == 1)
            continue;
        for (int j = i * i; j <= n; j += i)
        {
            table[j] = 1;
        }
    }
    for (int i = 2; i < n; i++)
    {
        if (table[i] == 0)
            v.push_back(i);
    }
    return v;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    int i = 0;
    vector<int> V = sito(25000000);
    while (i < n)
    {
        cout << V[i] << "\n";
        i++;
    }
    return 0;
}
