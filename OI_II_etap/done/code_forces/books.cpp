#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 10;

int TAB[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, t, a;
    cin >> n >> t;
    for (int i = 0; i < n; i++)
        cin >> TAB[i];

    int head = -1, tail = 0, ans = 0, A = 0, curent_max = 0;
    while (head < n - 1)
    {
        if (A + TAB[head + 1] <= t)
        {
            head++;
            A += TAB[head];
        }
        else if (tail <= head)
        {
            A -= TAB[tail];
            tail++;
        }
        else
        {
            head++;
            A = 0;
            tail++;
        }

        curent_max = head - tail + 1;
        ans = max(ans, curent_max);
    }

    cout << ans << "\n";
    return 0;
}