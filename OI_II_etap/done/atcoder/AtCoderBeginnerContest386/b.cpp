#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    string s;
    int ans = 0;

public:
    inline void solve()
    {
        cin >> s;

        FOR(i, s.size(), 0)
        {
            ans++;
            if (s[i] == '0' && i + 1 < s.size() && s[i + 1] == '0')
                i++;
        }

        cout << ans << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve solution;
    solution.solve();

    return 0;
}