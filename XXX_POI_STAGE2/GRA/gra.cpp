#include <bits/stdc++.h>
using namespace std;
#warning change to 5e5+10
constexpr int M = 2010;
int Sajz[M];
vector<int> Tree[M];
int depth[M];
int depth2[M];
void dfs(int v, int p)
{
    Sajz[v] = 1;
    for (int w : Tree[v])
        if (w != p)
        {
            dfs(w, v);
            Sajz[v] += Sajz[w];
        }
}
void depthcount(int v, int p, int d)
{
    depth[v] = d;
    for (int w : Tree[v])
        if (w != p)
            depthcount(w, v, d + 1);
}
void depthcount2(int v, int p, int d)
{
    depth2[v] = d;
    for (int w : Tree[v])
        if (w != p)
            depthcount2(w, v, d + 1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("gra2ocen.in", "r", stdin);
    int n, a, b, A, B, q;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }
    cin >> A >> B >> q;
    vector<int> zbiorA(A);
    vector<int> ZbiorB(B);
    for (int i = 0; i < A; i++)
        cin >> zbiorA[i];
    for (int i = 0; i < B; i++)
        cin >> ZbiorB[i];
    // finding centroid
    bool fint = 0, two = 0;
    int centroid = 1, past = 0;

    while (!fint)
    {
        dfs(centroid, centroid);
        fint = 1;
        two = 0;
        for (int w : Tree[centroid])
        {
            if (Sajz[w] > n / 2 && Sajz[w] != 0)
            {
                if (w == past)
                    two = 1;
                else
                {
                    past = centroid;
                    centroid = w;
                    fint = 0;
                    break;
                }
            }
            if (Sajz[w] == n / 2)
                two = 1, past = w;
        }
    }
    depthcount(centroid, centroid, 0);
    if (two)
        depthcount2(past, past, 0);
    long long res = 0;
    for (int a : zbiorA)
        for (int b : ZbiorB)
            if (a != b && depth[a] <= depth[b] && (!two || depth2[a] <= depth2[b]))
                res++;
    cout << res;
    return 0;
}