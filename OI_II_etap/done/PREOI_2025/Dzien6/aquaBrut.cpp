#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

typedef long long ll;

class Solve
{
protected:
    int Q;

    struct grupa
    {
        int ile = 0;
        int id = 0;
        int c = 0;
    };
    set<pair<int, ll>> Ans;
    ll ponton;

    vector<grupa> V;

public:
    inline void solve()
    {
        cin >> Q;

        int id_grupy = 0;

        while (Q--)
        {
            char operacja;

            cin >> operacja;

            if (operacja == 'D')
            {
                id_grupy++;
                int z, c;

                cin >> z >> c;

                V.push_back({z, id_grupy, c});
            }

            else if (operacja == 'R')
            {
                int id;
                cin >> id;

                for (auto &w : V)
                    if (w.id == id)
                        w.ile = 0;
            }

            else
            {
                cin >> ponton;
                Ans.clear();

                for (auto &w : V)
                    if (w.ile != 0 && ponton > 0)
                    {
                        if (w.ile <= ponton)
                        {
                            Ans.insert({w.id, w.ile});
                            ponton -= w.ile;
                            w.ile = 0;
                        }
                        else if (w.c == 1 && w.ile > ponton)
                        {
                            Ans.insert({w.id, ponton});
                            w.ile -= ponton;
                            ponton = 0;
                        }
                    }

                cout << Ans.size() << '\n';

                if (Ans.size() > 0)
                    for (auto w : Ans)
                        cout << w.first << " " << w.second << "\n";
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve s;
    s.solve();

    return 0;
}