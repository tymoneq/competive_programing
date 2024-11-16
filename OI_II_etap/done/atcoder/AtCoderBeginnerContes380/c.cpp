#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<pair<int, int>> Segment;

    int pocz = -1;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1' && pocz == -1)
            pocz = i;

        else if (s[i] == '0' && pocz != -1)
        {
            Segment.push_back({pocz, i - 1});
            pocz = -1;
        }

        if (i == n - 1 && pocz != -1)
            Segment.push_back({pocz, i});

        if (Segment.size() == k)
            break;
    }

    vector<char> ans;

    for (int i = 0; i < n; i++)
    {
        if (i == Segment[k - 2].second + 1)
            for (int j = Segment[k - 1].first; j <= Segment[k - 1].second; j++)
                ans.push_back(s[j]);

        else if (i == Segment[k - 1].first)
        {
            i = Segment[k - 1].second + 1;
            if (i == n)
                break;
        }

        ans.push_back(s[i]);
    }

    for (char a : ans)
        cout << a;

    cout << "\n";
    return 0;
}