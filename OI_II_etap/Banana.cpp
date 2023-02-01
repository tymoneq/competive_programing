#include <bits/stdc++.h>

using namespace std;
constexpr long long N = 1e18;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T, z = 0;
    long long n, tmp, ind = 27, val = 26;
    map<long long, char> M;
    while (ind <= N)
    {
        M[ind] = 'A' + z;
        if ('A' + z == 'Z')
        {
            z = 0;
            ind += val;
            val *= 26;
        }
        else
        {
            z++;
            ind += val;
        }
    }

    cin >> T;
    vector<char> Res;
    for (int t = 0; t < T; t++)
    {
        cin >> n;
        tmp = n;
        Res.clear();
        while (n > 26)
        {
            auto it = M.lower_bound(n);
            if (it->first != n)
                it--;
            Res.push_back(it->second);
            n -= it->first;
        }
        if (tmp > 26)
            n++;
        Res.push_back('A' + (n - 1));
        for (auto w : Res)
            cout << w;
        cout << "\n";
    }
    return 0;
}