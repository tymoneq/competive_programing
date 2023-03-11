#include <bits/stdc++.h>

using namespace std;
constexpr int M = 2e5 + 10;
int Arr[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> Arr[i];
    int mx = 0;
    vector<int> V;
    for (int i = 0; i < n - k; i++)
    {
        V.clear();
        for (int j = i; j < i + k; j++)
            V.push_back(Arr[j]);
        sort(V.begin(), V.end());
        mx = max(mx, V[k / 2]);
        for (int j = i + k; j < n; j++)
        {
            V.push_back(Arr[j]);
            sort(V.begin(), V.end());
            mx = max(mx, V[(j - i) / 2]);
        }
    }
    cout << mx;
    return 0;
}