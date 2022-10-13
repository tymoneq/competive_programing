#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> G[n];
    vector<int> G_kwad[n];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    for (int i = 0; i < n; i++)
    {
        for (auto el : G[i])
        {
            G_kwad[i].push_back(el);
            int val = el;
            for (auto ell : G[val])
            {
                if (find(G_kwad[i].begin(), G_kwad[i].end(), ell) != G_kwad->end())
                {
                    G_kwad[i].push_back(ell);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
        for (auto el : G_kwad[i])
        {
            cout << el << " ";
        }
        cout << endl;
    }
    return 0;
}
