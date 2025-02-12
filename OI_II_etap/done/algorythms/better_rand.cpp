#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
public:
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    mt19937_64 rd(seed);

    int n = rd() % 10 + 1;

    cout << n << '\n';

    FOR(i, n, 0)
    {
        int a = rd() % 1000;
        cout << a << '\n';
    }

    vector<int> Nums = {1, 2, 3, 4, 5, 6, 7};

    shuffle(Nums.begin(), Nums.end(), rd);

    for (int w : Nums)
        cout << w << " ";

    return 0;
}