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

    int n;
    cin >> n;
    set<int> NieWystepuja;
    vector<int> Skarpetki(n + 1);

    FOR(i, n + 2, 1)
    NieWystepuja.insert(i);

    FOR(i, n, 0)
    {
        cin >> Skarpetki[i];

        if (NieWystepuja.count(Skarpetki[i]))
            NieWystepuja.erase(Skarpetki[i]);
    }

    FOR(i, n, 0)
    {
        cout << *NieWystepuja.begin() << ' ';
        NieWystepuja.erase(NieWystepuja.begin());

        if (Skarpetki[i] != Skarpetki[i + 1])
            NieWystepuja.insert(Skarpetki[i]);
    }
    return 0;
}