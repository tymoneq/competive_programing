#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, a, j = 0;
    long long sum_of_even = 0, sum_of_odd = 0;
    vector<int> Num;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        sum_of_even = 0, sum_of_odd = 0, j = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            Num.push_back(a);
        }
        sort(Num.begin(), Num.end());

        while (j < Num.size())
        {
            if (j % 2 == 0)
            {
                if (Num[Num.size() - j - 1] % 2 == 0)
                    sum_of_even += Num[Num.size() - j - 1];
            }
            else if (Num[Num.size() - j - 1] % 2 != 0)
                sum_of_odd += Num[Num.size() - j - 1];
            j++;
        }
        if (sum_of_even > sum_of_odd)
            cout << "Alice\n";
        else if (sum_of_even == sum_of_odd)
            cout << "Tie\n";
        else
            cout << "Bob\n";
        Num.clear();
    }
    return 0;
}