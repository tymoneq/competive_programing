#include <bits/stdc++.h>
#include <cstdint>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int32_t k, n;

    cin >> k >> n;

    vector<vector<int32_t>> Meetings(k + 1, vector<int32_t>());
    vector<vector<int32_t>> LevelCost(k + 1, vector<int32_t>());
    Meetings[0].resize(n);
    Meetings[1].resize(n);
    LevelCost[0].resize(n);
    LevelCost[1].resize(n);

    int32_t mx = 0;

    for (int32_t i = 2; i <= k; i++) {
        int32_t ki;
        cin >> ki;
        Meetings[i].resize(ki);
        LevelCost[i].resize(ki);

        for (int32_t j = 0; j < ki; j++) {
            cin >> Meetings[i][j];
            Meetings[i][j]--;
        }
    }

    //  calculating cost

    for (int32_t i = k; i > 0; i--) {
        int32_t current_res = 0;
        for (int32_t j = 0; j < Meetings[i].size(); j++) {
            if (LevelCost[i][j] == 0)
                current_res++;
            else
                current_res += LevelCost[i][j];

            if (Meetings[i][j] != -1) {
                if (LevelCost[i][j] == 0)
                    LevelCost[i - 1][Meetings[i][j]]++;
                else
                    LevelCost[i - 1][Meetings[i][j]] += LevelCost[i][j];
            }
        }

        mx = max(mx, current_res);
    }

    cout << mx << "\n";

    return 0;
}