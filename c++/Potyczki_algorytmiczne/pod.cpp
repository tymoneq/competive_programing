#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, a, j = 0, mini = 0;
    pair<int, int> maxi;
    cin >> n >> k;
    j = n - 1;
    vector<int> Data(n);
    vector<pair<int, int>> V(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        Data[i] = a;
    }

    cout << "NIE";
    return 0;
}