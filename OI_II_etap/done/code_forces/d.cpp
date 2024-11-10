#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e8;

struct Alice
{
    int card_number, character_id;
};

map<int, char> characters;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    characters[0] = 'q', characters[1] = 'k', characters[2] = 'j';

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> Permutations(3, vector<int>(n + 1, 0));
        vector<bool> Used(n + 1, 0);
        vector<int> dp(n + 1, INF);
        vector<Alice> backtrackDP(n + 1);

        for (int i = 0; i < 3; i++)
            for (int j = 1; j <= n; j++)
                cin >> Permutations[i][j];

        dp[1] = 0;

        queue<int> q;
        q.push(1);
        while (!q.empty())
        {
            int state = q.front();
            q.pop();
            if (Used[state])
                continue;

            Used[state] = 1;

            for (int j = state + 1; j <= n; j++)
                for (int i = 0; i < 3; i++)
                    if (Permutations[i][j] < Permutations[i][state] && dp[state] + 1 < dp[j])
                    {
                        dp[j] = dp[state] + 1;
                        backtrackDP[j] = {state, i};
                        q.push(j);
                    }
        }

        if (dp[n] == INF)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        cout << dp[n] << "\n";

        vector<pair<char, int>> backtrack;
        int card = n;
        while (card != 1)
        {
            backtrack.push_back({characters[backtrackDP[card].character_id], card});
            card = backtrackDP[card].card_number;
        }

        for (int i = backtrack.size() - 1; i >= 0; i--)
            cout << backtrack[i].first << " " << backtrack[i].second << "\n";
    }

    return 0;
}