#include <bits/stdc++.h>

using namespace std;
#define f(n) for (int i = 0; i < n; i++)
const int MAX_VAL = 2e5 + 10;
int FA[MAX_VAL];
inline int p(int x)
{
    return x == FA[x] ? x : FA[x] = p(FA[x]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, a, b, w, g, res = 0;
    cin >> n >> k;
    f(n + 1)
        FA[i] = i;
    f(k)
    {
        cin >> a >> b;
        a = p(a);
        b = p(b);
        if (a == b)
            res++;
        else
            FA[a] = b;
    }
    cout << res;
    return 0;
}