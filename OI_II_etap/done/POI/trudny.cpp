#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
set<ll> Ans;
vector<int> Primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
inline void calc(ll &num, vector<int> &Czynniki, ll n, int &indx, ll step)
{
    while (num <= n)
    {
        if (num * Primes[indx] <= n)
        {
            num *= Primes[indx];
            Czynniki.push_back(Primes[indx]);
            indx++;
        }
        else if (num * Primes[indx] > n && num * step <= n)
        {
            num *= step;
            Czynniki.push_back(step);
        }
        else if (step == 3 && num * Primes[indx] > n && num * step > n && num * 2 <= n)
        {
            num *= 2;
            Czynniki.push_back(2);
        }
        else
            break;
    }
}

inline void generatingMasks(vector<int> &Czynniki)
{
    int masks = (1 << (Czynniki.size() + 1)) - 1;

    for (int i = 0; i <= masks; i++)
    {
        ll a = 1;

        for (int bit = 0; bit < Czynniki.size(); bit++)
            if ((i >> bit) & 1)
                a *= Czynniki[bit];

        Ans.insert(a);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    int indx = 0;
    ll num1 = 1, num2 = 1;
    vector<int> Czynniki1, Czynniki2;

    calc(num1, Czynniki1, n, indx, 2);
    calc(num2, Czynniki2, n, indx, 3);

    generatingMasks(Czynniki1);
    generatingMasks(Czynniki2);

    cout << Ans.size() << "\n";
    cout << num1 << " " << num2 << "\n";
    return 0;
}