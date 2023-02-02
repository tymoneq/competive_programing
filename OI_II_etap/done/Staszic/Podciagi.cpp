#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1e9 + 7;
inline long long pot(long long a, long long b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
    {
        long long tmp = pot(a, b / 2);
        return (tmp * tmp);
    }
    else
        return a * (pot(a, b - 1));
}
constexpr int M = 30;
int Arr[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> Arr[i];
    long long bits = n;
    long long pow_set_size = pot(2, bits);
    long long ans = 0;
    vector<string> List;
    for (long long counter = 0; counter < pow_set_size; counter++)
    {
        string tmp = "";
        for (long long j = 0; j < bits; j++)
            if (counter & (1 << j))
                tmp += to_string(Arr[j]) + "$";

        if (find(List.begin(), List.end(), tmp) == List.end())
        {
            ans++;
            ans %= MOD;
            List.push_back(tmp);
        }
    }
    cout << ans;
    return 0;
}