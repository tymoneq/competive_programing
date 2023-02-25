#include <bits/stdc++.h>

using namespace std;

constexpr int M = 2e5 + 10;
int MINindx[M], JMP[M], Height[M], IND[M];
struct parkur
{
    int l, r, MAX;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> Height[i];

    MINindx[Height[n]] = n;
    JMP[n] = n;
    for (int i = n - 1; i > 0; i--)
    {
        if (MINindx[Height[i] + 1] == 0)
            JMP[i] = i;
        else
            JMP[i] = MINindx[Height[i] + 1];
        MINindx[Height[i]] = i;
    }
    vector<parkur> Parkur;
    int prev = 0;
    for (int i = 1; i <= n; i++)
        if (Height[i] == 1)
        {
            int jmp = i;
            int r = n, val = 1;
            Parkur.push_back({i, i, val});
            IND[prev] = Parkur.size() - 1;
            prev = i;
            while (JMP[jmp] != jmp)
            {
                jmp = JMP[jmp];
                r = jmp;
                val++;
                Parkur.push_back({i, r, val});
            }
        }
    int lo, hi, mid, ansl, ansr;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        lo = 0, hi = Parkur.size() - 1;
        ansr = -1;
        ansl = -1;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (Parkur[mid].l < a)
                lo = mid + 1;
            else
            {
                hi = mid - 1;
                ansl = mid;
            }
        }
        if (ansl == -1)
        {
            cout << 0 << "\n";
            continue;
        }
        lo = ansl, hi = IND[Parkur[ansl].l];
        hi--;
        if (IND[Parkur[ansl].l] == 0)
            hi = Parkur.size() - 1;

        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (Parkur[mid].r <= b)
            {
                lo = mid + 1;
                ansr = mid;
            }
            else
                hi = mid - 1;
        }

        int mx = 0;
        if (ansl != -1 && ansr != -1)
            mx = Parkur[ansr].MAX;

        cout << mx << "\n";
    }
    return 0;
}