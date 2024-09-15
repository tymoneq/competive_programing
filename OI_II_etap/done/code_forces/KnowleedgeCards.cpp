#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m, k, a;
    cin >> t;

    while (t--)
    {
        queue<int> Q;
        priority_queue<int> pq;
        bool T = 1;
        cin >> n >> m >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> a;
            Q.push(a);
        }

        while (!Q.empty() || !pq.empty())
        {
            if (n * m - 2 - pq.size() <= 1)
            {
                T = 0;
                break;
            }
            if (!pq.empty() && pq.top() == k)
            {
                k--;
                pq.pop();
            }
            else if (!Q.empty() && Q.front() == k)
            {
                k--;
                Q.pop();
            }
            else if (!Q.empty() && Q.front() != k)
            {
                pq.push(Q.front());
                Q.pop();
            }
        }

        cout << (T ? "YA\n" : "TIDAK\n");
    }

    return 0;
}