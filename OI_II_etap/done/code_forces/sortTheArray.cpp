#include <bits/stdc++.h>

using namespace std;

inline bool sorto(pair<int, int> &l, pair<int, int> &r) { return l.first < r.first; }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, changes = 0;
    cin >> n;
    vector<pair<int, int>> Tab(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> Tab[i].first;
        Tab[i].second = i;

        if (i >= 3)
        {
            if (Tab[i - 2].first < Tab[i - 1].first && Tab[i - 1].first > Tab[i].first)
                changes++;
            if (Tab[i - 2].first > Tab[i - 1].first && Tab[i - 1].first < Tab[i].first)
                changes++;
        }
    }

    if (changes == 0)
    {
        cout << "yes" << "\n";
        if (Tab[2].first > Tab[1].first)
            cout << 1 << " " << 1 << "\n";
        else
            cout << 1 << " " << n << "\n";
    }

    else
    {
        sort(Tab.begin(), Tab.end(), sorto);
        changes = 0;
        for (int i = 3; i <= n; i++)
        {
            if (Tab[i - 2].second < Tab[i - 1].second && Tab[i - 1].second > Tab[i].second)
                changes++;
            if (Tab[i - 2].second > Tab[i - 1].second && Tab[i - 1].second < Tab[i].second)
                changes++;
        }
        if (changes > 2)
            cout << "no\n";
        else
        {
            int l = 0, r = 0;
            for (int i = 1; i <= n; i++)
                if (Tab[i].second != i)
                {
                    if (l != 0)
                        r = max(r, i);

                    else
                        l = i;
                }

            bool T = 1;
            for (int i = l + 1; i <= r; i++)
                if (T && abs(Tab[i].second - Tab[i - 1].second) != 1)
                    T = 0;

            if (T)
                cout << "yes\n"
                     << l << " " << r << "\n";
            else
                cout << "no\n";
        }
    }

    return 0;
}