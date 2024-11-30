#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, d;
    cin >> n >> d;

    int empty = 0, full = 0;
    for (int i = 0; i < n; i++)
    {
        char a;
        cin >> a;
        if (a == '.')
            empty++;
        else
            full++;
    }

    cout << empty + min(full, d) << '\n';
    return 0;
}