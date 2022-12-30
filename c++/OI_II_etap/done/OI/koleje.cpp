#include <bits/stdc++.h>
using namespace std;
const int base = 1 << 16;
int Tree[base << 1], Tree2[base << 1];
bool free_space = 1;
queue<int> q;
int p, k, value_to_rem;
void uptd(int v)
{
    v /= 2;
    while (v > 0)
    {
        Tree[v] = min(Tree[v * 2], Tree[v * 2 + 1]);
        v /= 2;
    }
}
void querymin(int v, int a, int b)
{
    if (b < p || k < a)
        return;
    else if (p <= a && b <= k)
    {
        if (free_space == 0)
            return;
        if (Tree[v] - value_to_rem < 0)
            free_space = 0;
        else
            q.push(v);

        return;
    }
    else
    {
        int l = v * 2, r = (v * 2) + 1, mid = (a + b) / 2;
        Tree[l] += Tree2[v];
        Tree[r] += Tree2[v];
        Tree2[l] += Tree2[v];
        Tree2[r] += Tree2[v];
        Tree2[v] = 0;
        querymin(l, a, mid);
        querymin(r, mid + 1, b);
        Tree[v] = min(Tree[l], Tree[r]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, z, a, b;
    cin >> n >> m >> z;
    for (int i = 1; i < base << 1; i++)
        Tree[i] = m;
    for (int i = 0; i < z; i++)
    {
        free_space = 1;
        cin >> p >> k >> value_to_rem;
        p--, k--;
        querymin(1, 0, base - 1);
        if (free_space)
        {
            cout << "T\n";
            while (!q.empty())
            {
                Tree[q.front()] -= value_to_rem;
                Tree2[q.front()] -= value_to_rem;
                uptd(q.front());
                q.pop();
            }
        }
        else
        {
            cout << "N\n";
            while (!q.empty())
            {
                uptd(q.front());
                q.pop();
            }
        }
    }
    return 0;
}