#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, index = 0, h = 0, a, v;
    cin >> n >> k;
    index = k / 2;
    if (k % 2 == 0)
        index--;
    vector<int> C(n);
    vector<int> tmp(k);
    for (int i = 0; i < k; i++)
    {
        cin >> C[i];
        tmp[i] = C[i];
    }
    sort(tmp.begin(), tmp.end());
    cout << tmp[index] << " ";
    for (int i = k; i < n; i++)
    {
        cin >> a;
        C[i] = a;
        auto itr = find(tmp.begin(), tmp.end(), C[h]);
        h++;
        v = itr - tmp.begin();
        tmp[v] = a;

        sort(tmp.begin(), tmp.end());
        cout << tmp[index] << " ";
    }
    return 0;
}