#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    int N;
    vector<int> A;
    stack<pair<int, int>> Stack;

public:
    inline void solve()
    {
        cin >> N;
        A.resize(N + 1);
        Stack.push({0, 0});

        FOR(i, N + 1, 1)
        cin >> A[i];

        FOR(i, N + 1, 1)
        {
            while (!Stack.empty() && Stack.top().second >= A[i])
                Stack.pop();

            cout << Stack.top().first << ' ';
            Stack.push({i, A[i]});
        }

        cout << '\n';
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