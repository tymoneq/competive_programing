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

    int a, b, c;
    cin >> a >> b >> c;
    bool T = 0;
    if (a == b && b == c)
        T = 1;
    if (a + b == c)
        T = 1;
    if (a + c == b)
        T = 1;
    if (b + c == a)
        T = 1;

    cout << (T ? "Yes" : "No") << '\n';

    return 0;
}