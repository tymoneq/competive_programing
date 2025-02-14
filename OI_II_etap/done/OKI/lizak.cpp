#include <bits/stdc++.h>
using namespace std;
constexpr int M = 2e6 + 7, N = 1e6 + 10;
int ans[M][2];
char s[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, totalsum = 0, firstone = -1, lastone = -1, ptr1, ptr2, currentsum;

    cin >> n >> m;
    cin.ignore(1, '\n');
    cin.read(s, n);
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
    ptr1 = 0;
    ptr2 = n - 1;
    currentsum = totalsum;
    while (currentsum > 0)
    {
        ans[currentsum][0] = ptr1 + 1;
        ans[currentsum][1] = ptr2 + 1;
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
        ans[currentsum][0] = ptr1 + 1;
        ans[currentsum][1] = ptr2 + 1;
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
        if (ans[k][0] == 0 || k > totalsum)
            cout << "NIE\n";
        else
            cout << ans[k][0] << ' ' << ans[k][1] << '\n';
    }
    return 0;
}