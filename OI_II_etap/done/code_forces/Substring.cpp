#include <bits/stdc++.h>

using namespace std;

constexpr int N = 3e5 + 10;

vector<int> adj[N], ReverseAdj[N];
bool cykl;
string s;
int mx;
set<int> White, Gray, Black;

inline void cykle(int v)
{
    White.erase(v);
    Gray.insert(v);

    for (int w : adj[v])
        if (!Black.count(w))
        {
            if (White.count(w))
                cykle(w);
            else if (Gray.count(w))
                cykl = 1;
        }
    Gray.erase(v);
    Black.insert(v);
}

inline void calcRes(int v, multiset<char> A)
{
    A.insert(s[v - 1]);
    for (char i = 'a'; i <= 'z'; i++)
        mx = max(mx, (int)A.count(i));

    for (int w : ReverseAdj[v])
        calcRes(w, A);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m >> s;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        ReverseAdj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        White.insert(i);

    while (White.size() > 0)
    {
        auto it = White.begin();
        cykle(*it);
    }

    if (cykl)
    {
        cout << -1 << '\n';
        return 0;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (adj[i].size() == 0)
            q.push(i);

    multiset<char> A;
    while (!q.empty())
    {

        calcRes(q.front(), A);
        q.pop();
    }

    cout << mx << '\n';

    return 0;
}