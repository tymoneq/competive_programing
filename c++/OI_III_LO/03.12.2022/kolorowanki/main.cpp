#include <bits/stdc++.h>

using namespace std;
inline bool sortoo(pair<int, int> &lhs, pair<int, int> &rhs) { return lhs.first > rhs.first; }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n, a;
        cin >> n;
        vector<pair<int, int>> Data(n + 1);
        for (int j = 1; j <= n; j++)
        {
            cin >> a;
            Data[a] = make_pair(Data[a].first + 1, a);
        }
        int tmp = 0;
        if (n % 2 == 1)
            tmp = 1;
        sort(Data.begin(), Data.end(), sortoo);
        cout << Data[0].first + 1 + tmp << "\n";
    }

    return 0;
}