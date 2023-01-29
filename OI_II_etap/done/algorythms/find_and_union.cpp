#include <bits/stdc++.h>

using namespace std;
const int MAX_VAL = 10;
int R[MAX_VAL];
int Size[MAX_VAL];

inline int f(int a)
{
    if (R[a] == a)
        return a;
    return R[a] = f(R[a]); // działa gdy nie usuwamy sciężek f(R[a])
}
void join(int a, int b)
{
    if (f(R[a]) == f(R[b]))
        return;
    if (Size[a] > Size[b])
        swap(a, b);
    Size[b] += Size[a];
    R[a] = R[b];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (size_t i = 0; i < MAX_VAL; i++)
    {
        R[i] = i;
        Size[i] = 1;
    }

    return 0;
}