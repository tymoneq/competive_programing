#include <bits/stdc++.h>

using namespace std;
constexpr int M = 2e5 + 10;
int Tab[12];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("zan0.in", "r", stdin);
    vector<string> V(M);
    set<int> InFront;
    for (int i = 0; i < 10; i++)
        Tab[i] = -1;
    for (int i = 1; i <= 20000; i++)
    {
        cin >> V[i];
        InFront.insert(V[i][0] - '0');
    }
    for (int i = 0; i < 10; i++)
        if (!InFront.count(i))
        {
            Tab[i] = 0;
            break;
        }
    for (int i = 0; i < 10; i++)
    {
        if (Tab[i] != 0)
            Tab[i] = i + 1;
    }
    for (int i = 0; i < 9; i++)
        if (Tab[i] == 0)
            Tab[9] = i;

    // for (int i = 1; i <= 20000; i++)
    // {
    //     for (char z : V[i])
    //         cout << Tab[z - '0'];
    //     cout << "\n";
    // }
    return 0;
}