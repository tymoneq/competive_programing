#include <bits/stdc++.h>

using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

typedef long long ll;

class Solve
{
protected:
    int a, b, N;

public:
    long long pot_szybkie(long long a, unsigned int n)
    {
        long long w = 1;

        while (n > 0)
        {
            if (n % 2 == 1) // jesli bit jest = 1
                w *= a;

            a *= a;
            n /= 2; // skrócenie o jeden bit
        }
        return w;
    }

    inline void solve()
    {
        cin >> N >> a >> b;

        bool ans = false;

        if (N % a == 0)
            ans = true;

        else if ((N - 1) % b == 0)
            ans = true;

        else
        {
            long long num = 1 + b;

            int MAXPOWER = 0;
            long long pot = 1;
            while (ll(pot * a )<= N)
            {
                pot *= a;
                MAXPOWER++;
            }


            while (num <= N)
            {
                int lo = 0, hi = MAXPOWER, mid;

                while (lo <= hi)
                {
                    mid = (lo + hi) / 2;

                    ll num2 = pot_szybkie(a, mid);

                    if (num * num2 == N)
                    {
                        ans = true;
                        break;
                    }
                    else if (num *num2  > N)
                        hi = mid - 1;

                    else
                        lo = mid + 1;
                }

                num += b;
                if (ans)
                    break;
            }
        }

        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        Solve solve;
        solve.solve();
    }

    return 0;
}