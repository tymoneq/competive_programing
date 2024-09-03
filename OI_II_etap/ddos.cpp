#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

struct package
{
    ll size = 0, package_recieve = 0;
    queue<pair<ll, ll>> V; // first time, second size
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, Q, a;
    string s;
    ll A, B, C, c_t, p_s, K = 1;
    map<string, package> M;
    cin >> T;
    while (T--)
    {
        cin >> Q;
        M.clear();

        for (int i = 0; i < Q; i++)
        {
            cin >> a;
            if (a == 2)
                cin >> A >> B >> C;

            else
            {
                cin >> s >> c_t >> p_s;
                while (!M[s].V.empty())
                {
                    auto el = M[s].V.front();
                    if (c_t - el.first + K > C)
                    {
                        M[s].package_recieve -= K;
                        M[s].size -= el.second;
                        M[s].V.pop();
                    }
                    else
                        break;
                }

                if (M[s].package_recieve >= A || M[s].size >= B)
                    cout << "ig" << "\n";

                else
                {
                    cout << "ac" << "\n";
                    M[s].package_recieve += K;
                    M[s].size += p_s;
                    M[s].V.push({c_t, p_s});
                }
            }
        }

        cout << "--" << "\n";
    }

    return 0;
}