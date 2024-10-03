#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e6 + 10;
pair<int, int> Ans[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    string lizak;

    cin >> n >> m >> lizak;

    for (int i = 0; i < n; i++)
    {
        int sum = (lizak[i] == 'T' ? 2 : 1);
        Ans[sum] = {i + 1, i + 1};
        for (int j = i + 1; j < n; j++)
        {
            sum += (lizak[j] == 'T' ? 2 : 1);
            Ans[sum] = {i + 1, j + 1};
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> k;
        if (Ans[k].first == 0)
            cout << "NIE";

        else
            cout << Ans[k].first << " " << Ans[k].second;
        cout << "\n";
    }

    return 0;
}
