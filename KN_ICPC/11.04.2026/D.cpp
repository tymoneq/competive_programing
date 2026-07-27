#include <bits/stdc++.h>
#include <ios>
#include <vector>

using namespace std;
int n, m, a, b;
vector<int> Race;

bool valid(int mid) {

    // lewo
    if (b < a) {

        int timer = a - b;
        if (mid >= timer)
            return false;

        int mxTimer = n - b;

        int current_time = 1;
        for (int j = mid - 1; j >= 0; j--) {

            if (Race[j] + current_time > mxTimer)
                return false;
            current_time++;
        }

    }
    // prawo
    else {

        int timer = b - a;

        //cout << timer << "\n";
        if (mid >= timer)
            return false;

        int mxTimer = b - 1;

        //cout << mxTimer << "\n";

        int current_time = 1;
        for (int j = mid - 1; j >= 0; j--) {

            if (Race[j] + current_time > mxTimer)
                return false;
            current_time++;
        }
    }

    return true;
}

inline void solve() {

    cin >> n >> m >> a >> b;

    Race.resize(m);
    for (int &v : Race)
        cin >> v;

    sort(Race.begin(), Race.end());

    int lo = 1, hi = m, ans = 0, mid;

    while (lo <= hi) {
        mid = (hi + lo) / 2;

        if (valid(mid)) {
            ans = mid;
            lo = mid + 1;

        } else {
            hi = mid - 1;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}