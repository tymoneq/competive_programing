#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> Ans;
void calc(int x, int y, int X)
{
    if (x > y)
        return;
    if (x * 2 == y || x * 2 + 1 == y)
    {
        Ans.push_back({X, y});
        return;
    }
    else
    {
        calc(x * 2, y, X);
        calc(x * 2 + 1, y, X);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, y;

    for (int i = 0; i < 1000; i++)
    {
        cin >> x >> y;
        calc(x, y, x);
    }

    for (auto el : Ans)
        cout << el.first << " " << el.second << "\n";

    return 0;
}