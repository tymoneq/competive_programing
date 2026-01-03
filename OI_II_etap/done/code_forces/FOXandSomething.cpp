#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

constexpr int N = 110;
constexpr int A = 40;

string Names[N];
vector<int> Graph[A];
int STO[A];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> Names[i];

    vector<char> ans;
    bool valid = true;

    for (int i = 0; i < n - 1; i++)
    {
        bool secondSmaller = (Names[i + 1].size() < Names[i].size() ? true : false);

        bool didAction = false;

        for (int j = 0; j < min(Names[i].size(), Names[i + 1].size()); j++)
        {
            if (Names[i][j] == Names[i + 1][j])
                continue;

            didAction = true;
            Graph[Names[i][j] - 'a'].push_back(Names[i + 1][j] - 'a');
            STO[Names[i + 1][j] - 'a']++;

            break;
        }

        if (!didAction && secondSmaller)
        {
            int index = Names[i + 1].size() - 1;
            Graph[Names[i][index] - 'a'].push_back(Names[i + 1][index] - 'a');
            STO[Names[i + 1][index] - 'a']++;
        }
    }

    queue<int> q;
    for (int i = 'a'; i <= 'z'; i++)
        if (STO[i - 'a'] == 0)
            q.push(i - 'a');

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        ans.push_back(v + 'a');

        for (int w : Graph[v])
        {
            STO[w]--;
            if (STO[w] == 0)
                q.push(w);
        }
    }
    for (int i = 'a'; i <= 'z'; i++)
        if (STO[i - 'a'] != 0)
            valid = false;

    // getting back ans

    if (!valid)
    {
        cout << "Impossible\n";
        return 0;
    }

    for (int i = 'a'; i <= 'z'; i++)
    {
        bool fint = false;
        for (char v : ans)
            if (v == i)
            {
                fint = true;
                break;
            }

        if (!fint)
            ans.push_back(i);
    }

    for (char v : ans)
        cout << v;

    cout << "\n";
    return 0;
}