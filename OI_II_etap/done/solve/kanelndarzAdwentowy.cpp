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
    set<int> Good = {1, 13, 17, 19, 21, 22, 23, 24};

    if (Good.count(n))
        cout << "TAK\n";
    else
        cout << "NIE\n";

    return 0;
}