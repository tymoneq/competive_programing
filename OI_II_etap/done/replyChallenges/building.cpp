#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    string z;
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        cin >> n;
        vector<vector<vector<int>>> V(5, vector<vector<int>>(n, vector<int>(n)));
        for (int i = 0; i < 5; i++)
        {
            cin >> z;
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    cin >> V[i][j][k];
        }
        vector<vector<int>> Res(n, vector<int>(n));
        

        cout << "Case #" << T << ":\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << Res[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}