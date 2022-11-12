#include <bits/stdc++.h>

using namespace std;

int count(vector<int> &coins, int n, int sum)
{
    vector<int> table(sum + 1);
    table[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = coins[i]; j <= sum; j++)
            table[j] += table[j - coins[i]];

    return table[sum];
}
int main()
{

    int sum, tmp;
    vector<int> coins;
    cin >> sum;
    while (cin >> tmp)
        coins.push_back(tmp);
    int n = coins.size();
    cout << count(coins, n, sum);
    return 0;
}