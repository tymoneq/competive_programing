#include <bits/stdc++.h>

using namespace std;
const int M = 1e5+10;
int PrefsumG[M], PrefsumH[M], Cows[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> Cows[i];
    for (int i = 1; i <= n; i++)
    {
        PrefsumG[i] = PrefsumG[i - 1];
        PrefsumH[i] = PrefsumH[i - 1];
        if (s[i - 1] == 'G')
            PrefsumG[i]++;
        else
            PrefsumH[i]++;
    }
    int LeaderG = -1;
    bool Leaderg = 0, leaderh = 0;
    int LeaderH = -1;
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == 'G' && PrefsumG[n] == PrefsumG[Cows[i]] && !Leaderg)
        {
            LeaderG = i,
            Leaderg = 1;
        }
        else if (s[i - 1] == 'G')
            Leaderg = 1;
        else if (s[i - 1] == 'H' && PrefsumH[n] == PrefsumH[Cows[i]] && !leaderh)
        {
            LeaderH = i,
            leaderh = 1;
        }
        else if (s[i - 1] == 'H')
            leaderh = 1;
    }
    int res = 0;
    if (LeaderG > LeaderH)
    {
        for (int i = LeaderG - 2; i >= 0; i--)
            if (s[i] == 'H' && Cows[i + 1] >= LeaderG)
                res++;
    }
    else
        for (int i = LeaderH - 2; i >= 0; i--)
            if (s[i] == 'G' && Cows[i + 1] >= LeaderH)
                res++;
    if (LeaderG != -1 && LeaderH != -1)
        res++;
    cout << res;
    return 0;
}