#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        if (k < n || n * n - n + 1 < k)
        {
            cout << "No\n";
            continue;
        }

        cout << "Yes\n";
        set<int> XD;

        for (int i = 1; i <= n * n; i++)
            XD.insert(i);

        vector<vector<int>> Grid(n, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            Grid[i][i] = k + i;
            XD.erase(k + i);
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (Grid[i][j] != 0)
                    continue;
                Grid[i][j] = *XD.begin();
                XD.erase(XD.begin());
            }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << Grid[i][j] << " ";

            cout << "\n";
        }
    }

    return 0;
}
