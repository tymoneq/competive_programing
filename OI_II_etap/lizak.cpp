#include <bits/stdc++.h>
using namespace std;
constexpr int M = 2e6 + 7;
pair<int, int> ans[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, totalsum = 0, firstone = -1, lastone = -1, ptr1, ptr2, currentsum;
    string s;
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'T')
            totalsum += 2;
        else
        {
            totalsum++;
            lastone = i;
            if (firstone == -1)
                firstone = i;
        }
    }
    for (int i = 0; i <= totalsum; i++)
        ans[i] = {-1, -1};
    ptr1 = 0;
    ptr2 = n - 1;
    currentsum = totalsum;
    while (currentsum > 0)
    {
        ans[currentsum] = {ptr1, ptr2};
        if (s[ptr1] == 'T')
            ptr1++;
        else if (s[ptr2] == 'T')
            ptr2--;
        else
        {
            ptr1++;
            ptr2--;
        }
        currentsum -= 2;
    }
    if (firstone <= (n - 1) - lastone)
    {
        ptr1 = firstone + 1;
        ptr2 = n - 1;
        currentsum = totalsum - (2 * firstone) - 1;
    }
    else
    {
        ptr1 = 0;
        ptr2 = lastone - 1;
        currentsum = totalsum - 2 * ((n - 1) - lastone) - 1;
    }
    while (currentsum > 0)
    {
        ans[currentsum] = {ptr1, ptr2};
        if (s[ptr1] == 'T')
            ptr1++;
        else if (s[ptr2] == 'T')
            ptr2--;
        else
        {
            ptr1++;
            ptr2--;
        }
        currentsum -= 2;
    }
    while (m--)
    {
        cin >> k;
        if (ans[k].first == -1 || k > totalsum)
            cout << "NIE\n";
        else
            cout << ans[k].first + 1 << ' ' << ans[k].second + 1 << '\n';
    }
    return 0;
}