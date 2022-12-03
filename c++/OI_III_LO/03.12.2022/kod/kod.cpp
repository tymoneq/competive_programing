#include <bits/stdc++.h>

using namespace std;
inline bool sorto(pair<int, int> &lhs, pair<int, int> &rhs) { return lhs.first < rhs.first; }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> Numbers(n + 1);
    vector<pair<int, int>> Res;
    vector<int> data(n - 2);
    int a;
    for (int i = 0; i < n - 2; i++)
    {
        cin >> a;
        data[i] = a;
        Numbers[a] += 1;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++)
        if (Numbers[i] == 0)
            pq.push(i);
    for (int i = 0; i < n - 2; i++)
    {
        Res.push_back(make_pair(min(data[i], pq.top()), max(data[i], pq.top())));
        pq.pop();
        Numbers[data[i]] -= 1;
        if (Numbers[data[i]] == 0)
            pq.push(data[i]);
    }
    int tmp = pq.top();
    pq.pop();
    Res.push_back(make_pair(min(tmp, pq.top()), max(tmp, pq.top())));
    sort(Res.begin(), Res.end(), sorto);
    for (auto el : Res)
        cout << el.first << " " << el.second << "\n";
    return 0;
}