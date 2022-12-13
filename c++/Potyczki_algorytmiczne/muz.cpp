#include <bits/stdc++.h>
using namespace std;
long long to_binary(long long n)
{
    int one_count = 0;
    while (n != 0)
    {
        if (n % 2 == 1)
            one_count++;
        n /= 2;
    }
    return one_count;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, one_count = 0, power_of_2 = 0, tmp = 0;
    long long num = 1;
    cin >> n;
    vector<long long> res;
    while (n > 0)
    {
        one_count = to_binary(num);
        tmp = log2(num);
        if (pow(2, tmp) == num)
            power_of_2++;
        if (n - power_of_2 == 1 || n - power_of_2 == 0)
        {
            res.push_back(pow(2, power_of_2) - 1);
            num = pow(2, power_of_2) - 1;
            n -= power_of_2;
        }
        else if (one_count <= n)
        {

            res.push_back(num);
            n -= one_count;
        }
        num++;
    }

    cout << res.size() << "\n";
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i] << " ";
    return 0;
}