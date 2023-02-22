#include <bits/stdc++.h>

using namespace std;
typedef unsigned int ui;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> Applicant(n);
    vector<ll> Sajz(m);
    for (int i = 0; i < n; i++)
        cin >> Applicant[i];
    for (int i = 0; i < m; i++)
        cin >> Sajz[i];
    sort(Applicant.begin(), Applicant.end());
    sort(Sajz.begin(), Sajz.end(), greater<ll>());
    ui res = 0, ind = 0;
    while (!Sajz.empty() && ind < n)
    {

        while (Applicant[ind] - k > Sajz[Sajz.size() - 1] && !Sajz.empty())
        {
            auto it = Sajz.end();
            it--;
            Sajz.erase(it);
        }
        if ((Applicant[ind] - k <= Sajz[Sajz.size() - 1] && Applicant[ind] >= Sajz[Sajz.size() - 1]) || (Applicant[ind] + k >= Sajz[Sajz.size() - 1] && Applicant[ind] <= Sajz[Sajz.size() - 1]))
        {
            res++;
            auto it = Sajz.end();
            it--;
            Sajz.erase(it);
        }
        ind++;
    }
    cout << res;
    return 0;
}