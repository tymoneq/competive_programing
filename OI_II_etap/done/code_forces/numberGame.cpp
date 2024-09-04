#include <bits/stdc++.h>

using namespace std;
const int N = 5e4 + 10;

bool check_prime(int n)
{
    for (int i = 2; i < min(n, N); i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    bool lose;
    string A = "Ashishgup\n", F = "FastestFinger\n";
    cin >> t;

    while (t--)
    {
        cin >> n;

        lose = (n == 1);

        if (n > 2 && n % 2 == 0)
        {
            if ((n & (n - 1)) == 0)
                lose = 1;
            else if (n % 4 != 0 && check_prime(n / 2))
                lose = 1;
        }

        if (lose)
            cout << F;
        else
            cout << A;
    }

    return 0;
}