#include <bits/stdc++.h>
using namespace std;
const int MAX_VAl = 10;
int num[MAX_VAl];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, T = 0, to_add = 0, tmp_log = 0, v;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        T = 0, to_add = 0;
        for (int j = 0; j < n; j++)
            cin >> num[j];
        for (int j = 1; j < n; j++)
        {
            if (num[j - 1] > num[j] + to_add)
            {
                T++;
                tmp_log = log2(num[j - 1] - num[j]);
                if (pow(2, tmp_log) < num[j - 1] - num[j])
                    tmp_log++;
                if (pow(2, T - 1) >= pow(2, tmp_log))
                    to_add = pow(2, T - 1);

                else
                {
                    v = pow(2, tmp_log) / pow(2, T - 1);
                    T += log2(v);
                    to_add = pow(2, T - 1);
                    T--;
                }
                num[j] += to_add;
            }
            else
                num[j] += to_add;
        }
        cout << T << "\n";
    }

    return 0;
}