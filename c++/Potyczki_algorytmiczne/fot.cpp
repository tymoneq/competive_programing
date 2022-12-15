#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a;
    cin >> n;
    vector<pair<int, int>> Data(n);
    vector<int> to_convert(n);
    vector<vector<int>> Res;
    vector<int> que;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        Data[i] = make_pair(a, i + 1);
    }
    sort(Data.begin(), Data.end());
    for (int i = 0; i < n; i++)
        to_convert[i] = Data[i].second;

    while (true)
    {
        for (int i = 0; i < n; i++)
        {
            if (to_convert[i] - 1 != 0)
            {
                
            }
        }
    }

    return 0;
}