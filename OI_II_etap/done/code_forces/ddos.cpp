#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct package
{
    ll package_size = 0;
    queue<pair<ll, ll>> q; // first time, second size
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, Q, a;
    cin >> T;

    while (T--)
    {
        cin >> Q;

        string s;
        ll alpha, beta, gamma, c_t, p_s;
        map<string, package> M;

        while (Q--)
        {
            cin >> a;
            if (a == 2)
                cin >> alpha >> beta >> gamma;

            else
            {
                cin >> s >> c_t >> p_s;

                while (!M[s].q.empty())
                {
                    if (c_t - gamma + (ll)1 > M[s].q.front().first)
                    {
                        M[s].package_size -= M[s].q.front().second;
                        M[s].q.pop();
                    }
                    else
                        break;
                }

                if ((ll)M[s].q.size() >= alpha || M[s].package_size >= beta)
                    cout << "ig" << "\n";

                else
                {
                    cout << "ac" << "\n";
                    M[s].package_size += p_s;
                    M[s].q.push({c_t, p_s});
                }
            }
        }

        cout << "--" << "\n";
    }

    return 0;
}