#include <bits/stdc++.h>

using namespace std;
int bin(int l, int r, int sum, int v, vector<int> &Sum, int index)
{
    int zak = l + (r - l) / 2;
    while (l <= r)
    {
        zak = l + (r - l) / 2;
        if (Sum[zak] - sum > v)
            r = zak;
        else
        {
            l = zak;
        }
        if (zak - index == 2)
            break;
    }
    return r;
}

inline bool sorto(int a, int b) { return a >= b; }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> B(n);
    for (int i = 0; i < n; i++)
        cin >> B[i];

    sort(B.begin(), B.end(), sorto);
    vector<int> sum(n);
    sum[0] = B[0];
    for (int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + B[i];

    int wynik = numeric_limits<int>::max();
    for (int i = 0; i < n - 2; i++)
    {

        int tmp = bin(i, n, sum[i], B[i], sum, i);
        wynik = min(tmp, wynik);
    }
    cout << B.size() - wynik - 1;
    return 0;
}