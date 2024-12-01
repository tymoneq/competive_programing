#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int K, M, N;
    cin >> K >> M >> N;

    vector<pair<int, int>> Patch(K);
    vector<int> NhojCows(M);

    for (auto &el : Patch)
        cin >> el.first >> el.second;

    for (int &a : NhojCows)
        cin >> a;
    sort(Patch.begin(), Patch.end());
    sort(NhojCows.begin(), NhojCows.end());

    vector<pair<int, int>> Ranges(K); // first - begining second end

    int l = -1e9 - 5, indx = 0;

    for (int i = 0; i < K; i++)
    {
        int r = NhojCows[indx];

        while (r < Patch[i].first)
        {
            l = r;
            if (indx == M - 1)
            {
                r = numeric_limits<int>::max();
                break;
            }
            indx++;
            r = NhojCows[indx];
        }

        int mnDist = min(abs(Patch[i].first - l), abs(Patch[i].first - r));

        Ranges[i] = {Patch[i].first - mnDist, Patch[i].first + mnDist};
    }

    priority_queue<ll> pq;

    int r = 0;
    l = 0;
    while (r < K)
    {
        l = r;
        ll sum = 0;
        while (Ranges[r].first < Ranges[l].second)
        {
            sum += Patch[r].second;
            r++;
            if (r == K)
            {
                break;
            }
        }
        pq.push(sum);
    }

    ll res = 0;
    while (!pq.empty() && N--)
    {
        res += pq.top();
        pq.pop();
    }

    cout << res << '\n';

    return 0;
}