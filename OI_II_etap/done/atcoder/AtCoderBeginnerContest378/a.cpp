#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, res = 0;
    map<int, int> A;
    for (int i = 0; i < 4; i++)
    {
        cin >> a;
        A[a]++;
    }

    for (auto el : A)
        res += (el.second / 2);

    cout << res << "\n";

    return 0;
}