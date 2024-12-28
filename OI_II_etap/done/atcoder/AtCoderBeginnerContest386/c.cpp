#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    int k;
    string s, T;
    int cnt = 1;

public:
    inline void solve()
    {
        cin >> k >> s >> T;

        if (s.size() == T.size())
        {
            FOR(i, s.size(), 0)
            {
                if (s[i] != T[i])
                    cnt--;
            }

            if (cnt >= 0)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        else if (s.size() + 1 == T.size())
        {
            int i = 0, j = 0;

            while (i < s.size() && j < T.size())
            {
                if (s[i] != T[j])
                {
                    cnt--;
                    j++;
                }
                i++, j++;
            }

            if (cnt >= 0)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        else if (s.size() - 1 == T.size())
        {

            int i = 0, j = 0;

            while (i < s.size() && j < T.size())
            {
                if (s[i] != T[j])
                {
                    cnt--;
                    i++;
                }
                i++, j++;
            }

            if (cnt >= 0)
                cout << "Yes\n";
            else
                cout << "No\n";
        }

        else
            cout << "No\n";
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