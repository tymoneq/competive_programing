#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, x, res;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        res = 0;
        set<int> NumbersToCheck, Answer;
        for (int i = 1; i * i <= n - x; i++)
        {
            if ((n - x) % i == 0)
            {
                if (i % 2 == 0)
                    NumbersToCheck.insert(i);
                if ((n - x) / i % 2 == 0)
                    NumbersToCheck.insert((n - x) / i);
            }
        }

        for (int i = 1; i * i <= n + x - 2; i++)
        {
            if ((n + x - 2) % i == 0)
            {
                if (i % 2 == 0)
                    NumbersToCheck.insert(i);
                if (((n + x - 2)) / i % 2 == 0)
                    NumbersToCheck.insert((n + x - 2) / i);
            }
        }
        for (int i : NumbersToCheck)
            Answer.insert(1 + i / 2);
        for (int k : Answer)
            if (k >= x)
                res++;
        cout << res << "\n";
    }

    return 0;
}