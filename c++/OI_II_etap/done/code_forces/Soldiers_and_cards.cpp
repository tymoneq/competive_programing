#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, l, res = 0, a, first = 0, second = 0, r = 0;
    queue<int> First_player;
    queue<int> Second_player;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> a;
        First_player.push(a);
    }
    cin >> l;
    for (int i = 0; i < l; i++)
    {
        cin >> a;
        Second_player.push(a);
    }
    while (!First_player.empty() && !Second_player.empty())
    {
        first = First_player.front();
        First_player.pop();
        second = Second_player.front();
        Second_player.pop();
        if (first > second)
        {
            First_player.push(second);
            First_player.push(first);
        }
        else
        {
            Second_player.push(first);
            Second_player.push(second);
        }
        res++;
        if ((res > n && n == 3) || res > 20000)
        {
            cout << -1;
            return 0;
        }
    }
    if (First_player.size() == 0)
        r = 2;
    else
        r = 1;
    cout << res << " " << r;
    return 0;
}
