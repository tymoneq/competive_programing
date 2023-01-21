#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, q, a, head, tail, res, current;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        cin >> n >> q;
        vector<int> Sweets(n);
        for (int i = 0; i < n; i++)
            cin >> Sweets[i];
        sort(Sweets.begin(), Sweets.end());
        for (int i = 0; i < q; i++)
        {
            cin >> a;
            head = 0, tail = 0, res = numeric_limits<int>::max(), current = 0;
            while (head < n)
            {
                current += Sweets[head];
                if (current >= a)
                {
                    while (current - Sweets[tail] >= a && tail < head)
                    {
                        current -= Sweets[tail];
                        tail++;
                    }
                    res = min(res, head - tail + 1);
                }
                head += 1;
            }
            cout << (res == numeric_limits<int>::max() ? -1 : res) << "\n";
        }
    }
    return 0;
}