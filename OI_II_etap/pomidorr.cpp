#include <bits/stdc++.h>

using namespace std;
vector<string> V;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    set<string> S;
    int n, q;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        S.insert(s);
    }
    V.resize(n);
    int ind = 0;
    for (auto w : S)
    {
        V[ind] = w;
        ind++;
    }
    cin >> q;
    int lo, hi, mid, ans;
    for (int i = 0; i < q; i++)
    {
        lo = 0, hi = n - 1;
        cin >> s;

        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            // if (valid(V[mid]))
            // {
            //     ans = mid;
            //     hi = mid - 1;
            // }
            // else
            //     lo = mid + 1;
        }
    }
}