#include <bits/stdc++.h>
using namespace std;

const int base = 1 << 19;
int N, K, Tree[base << 1], Tree_Max[base << 1], Tree2[base << 1], p, kon, sum;
queue<int> Q;
inline void updt(int v)
{
    v /= 2;
    while (v > 0)
    {
        Tree_Max[v] = Tree_Max[v * 2] + Tree_Max[v * 2 + 1];
        Tree[v] = max(Tree[v * 2], Tree[v * 2 + 1]);
        v /= 2;
    }
}

inline void add(int v, int a, int b)
{
    if (b < p || kon < a)
        return;
    else if (Tree[v] <= 0)
        return;
    else if (p <= a && b <= kon)
    {
        Tree[v] += 1;
        Tree2[v] += 1;
        if (Tree[v] >= K)
        {
            Q.push(v);
            int w;
            while (!Q.empty())
            {
                w = Q.front();
                Q.pop();
                if (w >= base)
                {
                    Tree[w] = numeric_limits<int>::min();
                    Tree_Max[w] = 1;
                    updt(w);
                    continue;
                }
                if (Tree[w * 2] + Tree2[w] >= K)
                    Q.push(w * 2);

                if (Tree[w * 2 + 1] + Tree2[w] >= K)
                    Q.push(w * 2 + 1);

                Tree[w * 2] += Tree2[w];
                Tree2[w * 2] += Tree2[w];
                Tree[w * 2 + 1] += Tree2[w];
                Tree2[w * 2 + 1] += Tree2[w];
                Tree2[w] = 0;
            }
        }
    }
    else
    {
        int l = v * 2, r = v * 2 + 1, mid = (a + b) / 2;
        Tree[l] += Tree2[v];
        Tree[r] += Tree2[v];
        Tree2[l] += Tree2[v];
        Tree2[r] += Tree2[v];
        Tree2[v] = 0;
        add(l, a, mid);
        add(r, mid + 1, b);
        Tree[v] = max(Tree[l], Tree[r]);
        Tree_Max[v] = Tree_Max[l] + Tree_Max[r];
    }
}
void inicjuj(int n, int k, int *D)
{
    N = n, K = k;
    for (int i = 0; i < n; ++i)
    {
        if (D[i] >= k)
        {
            Tree_Max[i + base] = 1;
            Tree[i + base] = numeric_limits<int>::min();
        }
        else
            Tree[i + base] = D[i];
    }
    for (int i = base - 1; i >= 1; i--)
    {
        Tree[i] = max(Tree[2 * i], Tree[2 * i + 1]);
        Tree_Max[i] = Tree_Max[i * 2] + Tree_Max[i * 2 + 1];
    }
}

void podlej(int a, int b)
{
    p = a, kon = b;
    add(1, 0, base - 1);
}

int dojrzale(int a, int b)
{
    sum = 0;
    a += base;
    b += base;
    if (a == b)
        return Tree_Max[a];
    sum += Tree_Max[a] + Tree_Max[b];
    while (a / 2 != b / 2)
    {
        if (a % 2 == 0)
            sum += Tree_Max[a + 1];
        a /= 2;
        if (b % 2 == 1)
            sum += Tree_Max[b - 1];
        b /= 2;
    }

    return sum;
}

