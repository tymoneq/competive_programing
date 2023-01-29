#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, res = 0, prev_val = 0;
    cin >> n;
    vector<int> V(n);
    for (int i = 0; i < n; i++)
        cin >> V[i];
    sort(V.begin(), V.end());
    for (int i = 0; i < n; i++)
        if (V[i] != prev_val)
        {
            res++;
            prev_val = V[i];
        }
    cout << res;
}