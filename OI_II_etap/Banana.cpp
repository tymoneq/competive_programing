#include <bits/stdc++.h>

using namespace std;
constexpr long long N = 1e18;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T, z = 0, l = 1;
    long long n, tmp, ind = 27, val = 26, pocz = 0;
    map<long long, pair<char, pair<long long, long long>>> M;
    while (ind <= N)
    {
        M[ind].first = 'A' + z;
        if ('A' + z == 'A')
            pocz = ind;
        M[ind].second.first = l;
        M[ind].second.second = val;
        if ('A' + z == 'Z')
        {
            z = 0;
            ind += val;
            val *= 26;
            l++;
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
        Res.clear();
        auto it = M.lower_bound(n);
        if (it->first != n)
            it--;
        int dl = it->second.second.second - 1;
        tmp = n - it->first;
        Res.push_back(it->second.first);
        while (dl > 0)
        {
            auto itr = M.lower_bound(it->second.second.first);
            itr--;
            while (itr->first > tmp)
            {
                itr--;
                if (itr->second.second.second == dl - 1)
                {
                    Res.push_back('A');
                    dl--;
                }
            }
            Res.push_back(itr->second.first);
            tmp -= itr->first;
            it = itr;
            dl--;
        }

        for (auto w : Res)
            cout << w;
        cout << "\n";
    }
    return 0;
}