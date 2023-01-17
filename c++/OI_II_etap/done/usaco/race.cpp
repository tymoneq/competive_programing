#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fout.tie(0);
    fin.open("race.in"), fout.open("race.out");
    int n, k;
    fin >> k >> n;
    vector<ll> X(n);
    for (int i = 0; i < n; i++)
        fin >> X[i];
    ll speed_up, slown_down = 0, t = 0;
    for (int i = 0; i < n; i++)
    {
        speed_up = 0, slown_down = 0, t = 0;
        for (int curr_spedd = 1;; curr_spedd++)
        {
            speed_up += curr_spedd;
            t++;
            if (slown_down + speed_up >= k)
                break;
            if (curr_spedd >= X[i])
            {
                slown_down += curr_spedd;
                t++;
                if (speed_up + slown_down >= k)
                    break;
            }
        }

        fout << t << "\n";
    }
    fin.close(), fout.close();
    return 0;
}