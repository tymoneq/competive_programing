#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> Osc(n), tmp;
    for (int i = 0; i < n; i++)
        cin >> Osc[i];
    long long sum_1, sum_2, res = 0;
    int count1 = 0, count2 = 0, x = 0, N = n;
    while (N > 0)
    {
        count1 = 0, sum_1 = 0, count2 = 0, sum_2 = 0;
        for (int i = 0; i < Osc.size(); i++)
            if (Osc[i] != 0)
            {
                if (i % 2 == 1)
                {
                    sum_1 += Osc[i];
                    count1++;
                }
                else
                {
                    sum_2 += Osc[i];
                    count2++;
                }
            }
        if (sum_1 > sum_2)
        {
            if (x % 2 == 0)
                res += sum_1;
            for (int i = 0; i < Osc.size(); i++)
                if (i % 2 == 0)
                    tmp.push_back(Osc[i]);
            N -= count1;
        }
        else
        {
            if (x % 2 == 0)
                res += sum_2;
            for (int i = 0; i < Osc.size(); i++)
                if (i % 2 == 1)
                    tmp.push_back(Osc[i]);
            N -= count2;
        }
        x++;
        Osc = tmp;
        tmp.clear();
    }
    cout << res;
}