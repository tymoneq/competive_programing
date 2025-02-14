#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    multiset<int> A, B;
    int N, M;

public:
    inline void read_data()
    {
        cin >> N >> M;

        FOR(i, N, 0)
        {
            int a;
            cin >> a;
            A.insert(a);
        }

        FOR(i, M, 0)
        {
            int a;
            cin >> a;
            B.insert(a);
        }
    }
    inline bool check(int num)
    {

        map<int, int> CNT;

        bool ans = false;
        CNT[num] = 1;
        map<int, int> Collected;

        set<int> Used;

        Used.insert(-num);

        while (!Used.empty())
        {
            int v = *Used.begin();
            v *= -1;

            if (CNT[v] > N)
                break;

            Used.erase(Used.begin());

            if (A.count(v) >= CNT[v])
                Collected[v] = CNT[v];

            else
            {
                Collected[v] = A.count(v);
                int ile_potrzeba = CNT[v] - A.count(v);
                CNT[v] = A.count(v);

                if (v % 2 == 0)
                {
                    int new_num = v / 2;

                    CNT[new_num] += ile_potrzeba * 2;

                    Used.insert(-(v / 2));
                    if (new_num == 0)
                        break;
                }
                else if (v % 2 == 1)
                {
                    int new_num = v / 2;

                    CNT[new_num] += ile_potrzeba;

                    CNT[new_num + 1] += ile_potrzeba;
                    Used.insert(-(v / 2));
                    Used.insert(-((v / 2) + 1));
                    if (new_num == 0)
                        break;
                }
            }
        }

        if (Used.size() == 0)
            ans = true;

        if (ans)
            for (auto &el : Collected)
                while (el.second--)
                {
                    auto it = A.find(el.first);
                    A.erase(it);
                }

        return ans;
    }

    inline void solve()
    {

        read_data();

        vector<int> To_erase;
        for (int el : B)
            if (A.count(el) > 0)
            {
                auto it = A.find(el);
                A.erase(it);

                To_erase.push_back(el);
            }

        for (int w : To_erase)
        {
            auto it = B.find(w);
            B.erase(it);
        }

        To_erase.clear();

        for (int w : B)
        {
            if (check(w))
                To_erase.push_back(w);
            else
                break;
        }

        for (int w : To_erase)
        {
            auto it = B.find(w);
            B.erase(it);
        }

        if (B.size() == 0 && A.size() == 0)
            cout << "YES\n";

        else
            cout << "NO\n";
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        Solve s;
        s.solve();
    }

    return 0;
}