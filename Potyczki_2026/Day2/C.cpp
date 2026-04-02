#include <bits/stdc++.h>
#include <cstdint>

using namespace std;
constexpr int32_t MAXN = 1e3 + 10;

int32_t Height[MAXN];
bool Off[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int32_t n, k;

    cin >> n >> k;

    for (int32_t i = 0; i < n; i++)
        cin >> Height[i];

    int64_t res = 0;

    for (int32_t rounds = 0; rounds < n; rounds++) {
        int32_t mx = -1;
        int32_t indx = -1;

        for (int32_t i = 0; i < n; i++)
            if (!Off[i] && mx < Height[i]) {
                mx = Height[i];
                indx = i;
            }
        if (indx == -1)
            continue;

        if (indx - 1 >= 0) {
            int32_t to_add = max((Height[indx] - k) - Height[indx - 1], 0);
            res += to_add;
            Height[indx - 1] += to_add;
        }

        if (indx + 1 < n) {
            int32_t to_add = max((Height[indx] - k) - Height[indx + 1], 0);
            res += to_add;
            Height[indx + 1] += to_add;
        }

        Off[indx] = true;
    }

    cout << res << "\n";

    return 0;
}