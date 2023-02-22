#include <bits/stdc++.h>

using namespace std;
constexpr int M = 1e7, N = 100;
bool notPrime[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    set<int> Prime;
    vector<int> RES(N);
    vector<int> Nums(N);
    for (int i = 0; i < N; i++)
        cin >> Nums[i];

    for (int i = 2; i * i < M; i++)
        if (!notPrime[i])
            for (int j = i * i; j < M; j += i)
                notPrime[j] = 1;
    int ind = 0;
    for (int i = 2; i < M; i++)
        if (!notPrime[i])
            Prime.insert(i);

    for (int i = 0; i < N; i++)
        for (int w : Prime)
        {
            if (w >= Nums[i] || w > Nums[i] / 2)
                break;
            if (Prime.find(Nums[i] - w) != Prime.end())
                RES[i]++;
        }
    pair<int, int> MX, MN;
    MX.first = 0, MX.second = 0, MN.first = numeric_limits<int>::max(), MN.second = numeric_limits<int>::max();
    for (int i = 0; i < N; i++)
    {
        if (RES[i] > MX.second)
        {
            MX.second = RES[i];
            MX.first = Nums[i];
        }
        if (RES[i] < MN.second && RES[i] != 0)
        {
            MN.second = RES[i];
            MN.first = Nums[i];
        }
    }
    cout << MX.first << " " << MX.second << " " << MN.first << " " << MN.second;
    return 0;
}