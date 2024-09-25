#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;

    int res = 0;
    char prev_winner;
    cin >> s;

    prev_winner = s[0];
    for (int i = 1; i < s.size(); i++)
        if (s[i] != prev_winner)
        {
            prev_winner = s[i];
            res++;
        }

    cout << res << "\n";
    return 0;
}