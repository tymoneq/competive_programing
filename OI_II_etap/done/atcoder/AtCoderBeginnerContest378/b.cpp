#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, Q, t, d;
    cin >> N;

    vector<pair<int, int>> Types(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> Types[i].first >> Types[i].second;

    cin >> Q;
    while (Q--)
    {
        cin >> t >> d;

        int current_phase = d % Types[t].first;

        if (current_phase <= Types[t].second)
            cout << d + (Types[t].second - current_phase) << "\n";

        else
            cout << d + (Types[t].first - (current_phase - Types[t].second)) << "\n";
    }

    return 0;
}