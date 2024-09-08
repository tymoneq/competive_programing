#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline bool sorto(pair<int, ll> &lhs, pair<int, ll> &rhs) { return lhs.first < rhs.first; }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, d;
    ll mx_friendship = 0, current_friendship = 0;
    int head = -1, tail = 0, current_min_money = 0;
    cin >> n >> d;

    vector<pair<int, ll>> Friends(n);
    for (auto &i : Friends)
        cin >> i.first >> i.second;

    sort(Friends.begin(), Friends.end(), sorto);

    while (head < n-1)
    {
        if (tail > head)
        {
            head++;
            current_min_money = Friends[head].first;
            current_friendship = Friends[head].second;
        }
        else if (tail == head && Friends[head + 1].first - Friends[head].first < d)
        {
            head++;
            current_friendship += Friends[head].second;
        }
        else if (tail == head && Friends[head + 1].first - Friends[head].first >= d)
        {
            current_friendship = 0;
            current_min_money = 0;
            tail++;
        }
        else if (tail < head && Friends[head + 1].first - current_min_money < d)
        {
            head++;
            current_friendship += Friends[head].second;
        }
        else if (tail < head && Friends[head + 1].first - current_min_money >= d)
        {
            current_friendship -= Friends[tail].second;
            tail++;
            current_min_money = Friends[tail].first;
        }
        mx_friendship = max(mx_friendship, current_friendship);
    }

    cout << mx_friendship << "\n";

    return 0;
}