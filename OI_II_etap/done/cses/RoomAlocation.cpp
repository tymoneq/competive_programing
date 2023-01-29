#include <bits/stdc++.h>

using namespace std;
struct RoomAlocation
{
    int arrival, departue, index;
};
inline bool sorto(const RoomAlocation &lhs, const RoomAlocation &rhs) { return lhs.arrival < rhs.arrival; }
int main()
{
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
    int rooms = 0, last_rooms=0;
    vector<int> R(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++)
    {
        if (pq.empty() || Guests[i].arrival <= pq.top().first)
        {
            last_rooms++;
            R[Guests[i].index] = last_rooms;
            pq.push({Guests[i].departue, last_rooms});
        }
        else
        {
            R[Guests[i].index] = pq.top().second;
            pq.pop();
            pq.push({Guests[i].departue, R[Guests[i].index]});
        }
        rooms = max(rooms, (int)pq.size());
    }
    cout << rooms << "\n";
    for (int w : R)
        cout << w << " ";
    return 0;
}