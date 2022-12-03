#include <bits/stdc++.h>

using namespace std;
inline bool sortoo(int &lhs, int &rhs) { return lhs > rhs; }
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
        vector<int> Data(n + 1);
        for (int j = 1; j <= n; j++)
        {
            cin >> a;
            Data[a] += 1;
        }
        int tmp = 0;
        sort(Data.begin(), Data.end(), sortoo);
        if (n % 2 == 1 && Data[0] == 1)
            tmp = 1;
        cout << Data[0] + 1 + tmp << "\n";
        Data.clear();
    }

    return 0;
}