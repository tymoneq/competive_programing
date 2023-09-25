#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int M = 5e5 + 10;
ll JMP[M], VAL[M];
bool off[M];
struct TIME
{
    ll p, k, time;
};
inline bool sorto(TIME &lhs, TIME &rhs)
{
    return lhs.time > rhs.time;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, res = 0, mx = 0, jmp;
    cin >> n;
    vector<TIME> Humans(n);
    for (int i = 0; i < n; i++)
    {
        cin >> Humans[i].p >> Humans[i].k;
        Humans[i].k -= 1;
        Humans[i].time = Humans[i].k - Humans[i].p;
    }
    sort(Humans.begin(), Humans.end(), sorto);
    for (int i = n - 1; i >= 0; i--)
        if (Humans[i].time >= 0)
        {
            mx = 0;
            jmp = i;
            for (int j = i + 1; j < n; j++)
                if (Humans[j].p >= Humans[i].p && Humans[j].k <= Humans[i].k && VAL[j] > mx)
                {
                    mx = VAL[j];
                    jmp = j;
                }
            
            VAL[i] = ++mx;
            JMP[i] = jmp;
        }
    mx = 0;
    for (int i = 0; i < n; i++)
        if (mx < VAL[i])
        {
            mx = VAL[i];
            jmp = i;
        }
    res = mx;
    while (jmp != JMP[jmp])
    {
        off[jmp] = 1;
        jmp = JMP[jmp];
    }
    off[jmp] = 1;
    for (int i = 0; i < n; i++)
        VAL[i] = 0, JMP[i] = 0;
    for (int i = n - 1; i >= 0; i--)
        if (Humans[i].time >= 0 && !off[i])
        {
            mx = 0;
            jmp = i;
            for (int j = i + 1; j < n; j++)
            {
                if (Humans[j].p >= Humans[i].p && Humans[j].k <= Humans[i].k && VAL[j] > mx && !off[j])
                {
                    mx = VAL[j];
                    jmp = j;
                }
            }
            VAL[i] = ++mx;
            JMP[i] = jmp;
        }
    mx = 0;
    for (int i = 0; i < n; i++)
        mx = max(mx, VAL[i]);

    res += mx;
    cout << res;
    return 0;
}