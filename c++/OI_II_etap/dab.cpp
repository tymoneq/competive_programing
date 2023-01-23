#include <bits/stdc++.h>

using namespace std;
constexpr int M = 5e3 + 10;
vector<int> Tree[M];
int Pre[M], Post[M], NumOfIll[M];
bool Vis[M];
int n, k, T, timer = 0;
set<int> Ill;
inline void preorder(int v)
{
    timer++;
    Pre[v] = timer;
    Vis[v] = 1;
    if (Ill.count(v))
    {
        Post[v] = timer;
        NumOfIll[v] = 1;
        return;
    }
    for (int w : Tree[v])
        if (!Vis[w])
        {
            preorder(w);
            NumOfIll[v] += NumOfIll[w];
        }
    Post[v] = timer;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> n >> k >> T;
    for (int i = 0; i < k; i++)
    {
        cin >> a;
        Ill.insert(a);
    }
    for (int i = 2; i <= n; i++)
    {
        Pre[i] = Post[i] = -1000;
        cin >> a >> b;
        Tree[a].push_back(b), Tree[b].push_back(a);
    }
    preorder(1);
    return 0;
}