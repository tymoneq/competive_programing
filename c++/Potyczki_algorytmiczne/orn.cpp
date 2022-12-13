#include <bits/stdc++.h>
// Tymon Tumialis
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, l = 0, r = 2;
    const int odp_min = pow(10, 9) * -1, odp_max = pow(10, 9);
    bool more = true;
    cin >> n;
    vector<int> V(n);
    vector<int> Res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> V[i];
        Res[i] = V[i];
    }

    while (r < n)
    {
        if (more)
        {
            if (Res[l] > Res[l + 1])
            {
                if (Res[l + 1] >= Res[r])
                {
                    if (Res[r] <= Res[r + 1])
                    {
                        Res[r] = odp_max;
                        r++;
                        l++;
                        more ^= 1;
                    }
                    else
                        Res[l + 1] = odp_min;
                }
            }
            else if (Res[l] <= Res[l + 1])
                Res[l + 1] = odp_min;
        }
        else if (!more)
        {
            if (Res[l] < Res[l + 1])
            {
                if (Res[l + 1] <= Res[r])
                    Res[r] = odp_min;
            }
            else if (Res[l + 1] >= Res[r])
                Res[l + 1] = odp_min;
        }
        l++;
        r++;
        more ^= 1;
    }
    int wynik = 0;
    for (int i = 0; i < n; i++)
    {
        if (Res[i] != V[i])
            wynik++;
        Res[i] = V[i];
    }
    r = 2;
    l = 0;
    more = false;
    while (r < n)
    {
        if (more)
        {
            if (Res[l] > Res[l + 1])
            {
                if (Res[l + 1] >= Res[r])
                {
                    if (Res[r] <= Res[r + 1])
                    {
                        Res[r] = odp_max;
                        r++;
                        l++;
                        more ^= 1;
                    }
                    else
                        Res[l + 1] = odp_min;
                }
            }
            else if (Res[l] <= Res[l + 1])
                Res[l + 1] = odp_min;
        }
        else if (!more)
        {
            if (Res[l] < Res[l + 1])
            {
                if (Res[l + 1] <= Res[r])
                    Res[r] = odp_min;
            }
            else if (Res[l] >= Res[l + 1])
                Res[l] = odp_min;
        }
        l++;
        r++;
        more ^= 1;
    }
    int wynikk = 0;
    for (int i = 0; i < n; i++)
        if (Res[i] != V[i])
            wynikk++;

    cout << min(wynik, wynikk);

    return 0;
}