#include <bits/stdc++.h>

using namespace std;
struct RoomAlocation
{
    int arrival, departue, index;
};
inline bool sorto(const RoomAlocation &lhs, const RoomAlocation &rhs) { return lhs.departue < rhs.departue; }
int main()
{
    // freopen("f.out", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<RoomAlocation> Guests(n);
    for (int i = 0; i < n; i++)
    {
        cin >> Guests[i].arrival >> Guests[i].departue;
        Guests[i].index = i;
    }
    sort(Guests.begin(), Guests.end(), sorto);
    int res = 0, v;
    vector<int> R(n);
    unordered_map<int, multiset<int>> M;
    multiset<int> Rooms;
    Rooms.insert(0);
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(Rooms.begin(), Rooms.end(), Guests[i].arrival);
        it--;
        if (it == Rooms.begin())
        {
            res++;
            R[Guests[i].index] = res;
            M[Guests[i].departue].insert(res);
            Rooms.insert(Guests[i].departue);
        }
        else
        {
            v = *it;
            Rooms.erase(it);
            R[Guests[i].index] = *(M[v].begin());
            Rooms.insert(Guests[i].departue);
            M[Guests[i].departue].insert(*(M[v].begin()));
            M[v].erase(M[v].begin());
        }
    }
    cout << res << "\n";
    for (int w : R)
        cout << w << " ";
    return 0;
}