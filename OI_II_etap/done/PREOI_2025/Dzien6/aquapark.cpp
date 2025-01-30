#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

typedef long long ll;
constexpr int base = 1 << 18;

ll DrzewoMin[base << 1];
ll DrzewoSum[base << 1];

class Solve
{
protected:
    int Q;
    vector<int> Type;
    const ll INF = 1e15 + 5;
    set<int> ID_sumy;
    set<pair<int, ll>> Ans;
    int id_grupy = 0;
    ll ponton;

public:
    inline void read_data()
    {
        cin >> Q;

        Type.resize(Q + 1);

        FOR(i, base + base, 0)
        DrzewoMin[i] = INF;
    }
    inline void upt_min(int v)
    {
        v /= 2;

        while (v > 0)
        {
            DrzewoMin[v] = min(DrzewoMin[v * 2], DrzewoMin[v * 2 + 1]);
            v /= 2;
        }
    }

    inline void upt_sum(int v)
    {
        v /= 2;

        while (v > 0)
        {
            DrzewoSum[v] = DrzewoSum[v * 2] + DrzewoSum[v * 2 + 1];
            v /= 2;
        }
    }

    inline int find_id(int v)
    {
        if (v > base)
            return v - base;

        if (DrzewoMin[v * 2] <= ponton)
            return find_id(v * 2);

        else if (DrzewoMin[v * 2 + 1] <= ponton)
            return find_id(v * 2 + 1);
    }

    inline ll query(int l, int r)
    {
        ll sum = 0;
        l += base;
        r += base;

        while (l / 2 != r / 2)
        {
            if (l % 2 == 0)
                sum += DrzewoSum[l + 1];

            if (r % 2 == 1)
                sum += DrzewoSum[r - 1];

            l /= 2, r /= 2;
        }

        return sum;
    }

    inline void gen_ans()
    {
        if (ponton == 0)
            return;

        int id = base - 1;

        // znajdź id
        if (DrzewoMin[1] <= ponton)
        {
            id = find_id(1);

            ll sum = query(0, id);

            // mieści się cały przedział
            if (sum <= ponton - DrzewoMin[id + base])
            {
                ponton -= sum;
                ponton -= DrzewoMin[id + base];

                Ans.insert({id, DrzewoMin[id + base]});
                DrzewoMin[id + base] = INF;
                upt_min(id + base);

                auto it = ID_sumy.upper_bound(id);

                vector<int> to_erease;

                for (auto itr = ID_sumy.begin(); itr != it; itr++)
                {
                    Ans.insert({*itr, DrzewoSum[*itr + base]});
                    DrzewoSum[*itr + base] = 0;
                    upt_sum(*itr + base);
                    to_erease.push_back(*itr);
                }

                for (int w : to_erease)
                    ID_sumy.erase(w);

                gen_ans();
            }
            else
            {
                auto it = ID_sumy.upper_bound(id);
                vector<int> to_erease;

                for (auto itr = ID_sumy.begin(); itr != it; itr++)
                {
                    if (ponton - DrzewoSum[*itr + base] >= 0)
                    {
                        Ans.insert({*itr, DrzewoSum[*itr + base]});
                        ponton -= DrzewoSum[*itr + base];
                        DrzewoSum[*itr + base] = 0;
                        upt_sum(*itr + base);
                        to_erease.push_back(*itr);
                    }
                    else
                    {
                        Ans.insert({*itr, ponton});
                        DrzewoSum[*itr + base] -= ponton;
                        upt_sum(*itr + base);
                        ponton = 0;

                        break;
                    }
                }

                for (int w : to_erease)
                    ID_sumy.erase(w);

                gen_ans();
            }
        }
        else
        {
            vector<int> to_erease;
            for (auto itr = ID_sumy.begin(); itr != ID_sumy.end(); itr++)
            {
                if (ponton - DrzewoSum[*itr + base] >= 0)
                {
                    Ans.insert({*itr, DrzewoSum[*itr + base]});
                    ponton -= DrzewoSum[*itr + base];
                    DrzewoSum[*itr + base] = 0;
                    upt_sum(*itr + base);
                    to_erease.push_back(*itr);
                }
                else
                {
                    Ans.insert({*itr, ponton});
                    DrzewoSum[*itr + base] -= ponton;
                    upt_sum(*itr + base);
                    ponton = 0;
                    break;
                }
            }

            for (int w : to_erease)
                ID_sumy.erase(w);
        }
    }

    inline void solve()
    {
        read_data();

        while (Q--)
        {
            char operacja;

            cin >> operacja;

            if (operacja == 'D')
            {
                id_grupy++;

                int z, c;
                cin >> z >> c;

                Type[id_grupy] = c;

                if (c == 0)
                {
                    DrzewoMin[id_grupy + base] = z;
                    upt_min(id_grupy + base);
                }

                else
                {
                    DrzewoSum[id_grupy + base] = z;
                    upt_sum(id_grupy + base);
                    ID_sumy.insert(id_grupy);
                }
            }

            else if (operacja == 'R')
            {
                int id;
                cin >> id;

                if (Type[id] == 1)
                {
                    DrzewoSum[id + base] = 0;
                    upt_sum(id + base);
                    ID_sumy.erase(id);
                }
                else
                {
                    DrzewoMin[id + base] = INF;
                    upt_min(id + base);
                }
            }

            else
            {
                cin >> ponton;
                Ans.clear();

                gen_ans();

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