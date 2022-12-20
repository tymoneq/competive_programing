#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, res = 0, index = 0;
    cin >> n;
    vector<int> Boys(n);
    for (int i = 0; i < n; i++)
        cin >> Boys[i];
    cin >> m;
    vector<int> Girls(m);
    for (int i = 0; i < m; i++)
        cin >> Girls[i];
    sort(Boys.begin(), Boys.end());
    sort(Girls.begin(), Girls.end());

    for (int i = 0; i < m; i++)
    {
        if (Boys.size() == 0 || Boys[Boys.size() - 1] + 1 < Girls[i])
            break;
        auto itr = lower_bound(Boys.begin(), Boys.end(), Girls[i]);
        if (*itr == Girls[i])
        {
            res++;
            Boys.erase(itr);
        }
        else
        {
            index = itr - Boys.begin();
            if (Boys[index - 1] + 1 == Girls[i])
            {
                res++;
                itr--;
                Boys.erase(itr);
            }
            else if (*itr - 1 == Girls[i])
            {
                res++;
                Boys.erase(itr);
            }
        }
    }

    cout << res;
    return 0;
}