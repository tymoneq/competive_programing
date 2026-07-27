#include <bits/stdc++.h>
#include <ios>
#include <utility>

using namespace std;

inline void move(pair<int, int> &location, char m) {

    if (m == 'L')
        location.first--;
    else if (m == 'R')
        location.first++;
    else if (m == 'U')
        location.second++;
    else if (m == 'D')
        location.second--;
}

inline pair<int, int> simulate(pair<int, int> current_location,
                               const pair<int, int> &Off, string &s, int i) {

    pair<int, int> next_move;
    for (int j = i + 1; j < s.size(); j++) {
        next_move = current_location;
        move(next_move, s[j]);

        if (next_move == Off)
            continue;
        else
            current_location = next_move;
    }

    return current_location;
}

inline void solve() {

    string s;
    cin >> s;

    pair<int, int> Off;
    pair<int, int> ans = {0, 0};
    set<pair<int, int>> used;
    pair<int, int> location = {0, 0};

    for (int i = 0; i < s.size(); i++) {
        // stoping before this move;

        Off = location;
        move(Off, s[i]);

        if (Off == make_pair(0, 0) || used.count(Off)) {
            move(location, s[i]);
            continue;
        }

        used.insert(Off);
        // simulate path if end = {0,0} => break

        if (simulate(location, Off, s, i) == make_pair(0, 0)) {
            ans = Off;
            break;
        }

        // chanching location
        move(location, s[i]);
    }

    cout << ans.first << " " << ans.second << "\n";
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
}