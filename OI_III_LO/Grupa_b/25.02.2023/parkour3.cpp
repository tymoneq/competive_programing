#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    unordered_map<int, vector<int>> Height;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        Height[a].push_back(i);
    }
    int ind = 0, val = 0;
    for (int i = 0; i < m; i++)
    {
        ind = 0, val = 0;
        cin >> a >> b;
        ind = a - 1;
        while (ind < b)
        {
            auto it = upper_bound(Height[val + 1].begin(), Height[val + 1].end(), ind);
            if (it == Height[val + 1].end())
                break;
            if (*it > b)
                break;
            val++;
            ind = *it;
        }
        cout << val << "\n";
    }
}