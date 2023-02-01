#include <bits/stdc++.h>

using namespace std;

// constexpr int M = 1e5 + 10;
// int Soldiers[M], N;
bool valid(int val, int &N, vector<int> &Soldiers)
{
    int rows = 1, In_row = 0;
    for (int i = 0; i < N; i++)
    {
        if (Soldiers[i] > val)
            return 0;
        if (In_row + Soldiers[i] <= val)
            In_row += Soldiers[i];
        else if (In_row + Soldiers[i] > val)
        {
            rows++;
            In_row = Soldiers[i];
        }
    }
    return rows <= val;
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int N;
    int a;
    scanf("%d", &N);
    vector<int> Soldiers(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a);
        Soldiers[i] = a;
    }
    int lo = 1, hi = N, ans = -1, mid;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (valid(mid, N, Soldiers))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }

    printf("%d", ans);
    return 0;
}