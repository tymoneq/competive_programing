#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

constexpr int N = 3e4 + 10;
set<int> adj[N];
vector<int> ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;

    cin >> n >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
    }

    for (int i = 1; i <= n; i++)
    {
        ans.push_back(i);
        int indx = ans.size() - 1;

        while (indx != 0)
        {
            if (adj[ans[indx - 1]].count(i))
            {
                swap(ans[indx], ans[indx - 1]);
                indx--;
            }
            else
                break;
        }
    }

    if (ans.size() == n)
        for (int w : ans)
            cout << w << ' ';

    else
        cout << -1;
    cout << '\n';
    return 0;
}