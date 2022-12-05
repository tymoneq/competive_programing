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
    long long  n, num, num_1, num_2, one_count_1, one_count_2;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        num_1 = (num - 1) * 2;
        num_2 = num_1 + 1;
        one_count_1 = to_binary(num_1);
        one_count_2 = to_binary(num_2);
        if (one_count_1 % 2 == 0)
            cout << num_1 << "\n";
        else
            cout << num_2 << "\n";
    }

    return 0;
}