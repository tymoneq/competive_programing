#include <bits/stdc++.h>
using namespace std;

// przepisywanie mniejszego do większego

const int M = 1e5 + 7;
int Rep[M];
vector<int> Zbior[M];
inline bool ten_sam_zbior(int a, int b) { return Rep[a] == Rep[b]; }

void add_edge(int a, int b)
{
    if (ten_sam_zbior(a, b))
        return;
    if (Zbior[Rep[a]].size() > Zbior[Rep[b]].size())
        swap(a, b);

    for (int w : Zbior[Rep[a]])
    {
        Zbior[Rep[b]].push_back(w);
        Rep[w] = Rep[b];
    }
    Zbior[Rep[a]].clear();
}

// kompresja ścieżek
//==============================================
int Sizee[M];
int R[M];

inline int fint(int v) { return R[v] == v ? v : R[v] = fint(R[v]); }

void onion(int a, int b)
{
    if (fint(a) == fint(b))
        return;
    if (Sizee[fint(a)] > Sizee[fint(b)])
        swap(a, b);
    R[a] = R[b];
    Sizee[b] += Sizee[a];
    Sizee[a] = 0;
}