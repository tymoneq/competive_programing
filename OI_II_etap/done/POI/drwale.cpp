#include <bits/stdc++.h>

using namespace std;

constexpr int A = 3e6 + 10;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> drewno(n);
    int total_sum = 0;

    for (int &a : drewno)
    {
        cin >> a;
        total_sum += a;
    }

    sort(drewno.begin(), drewno.end());

    int last_element = drewno[n - 1];
    auto it = drewno.end();
    it--;

    drewno.erase(it);
    total_sum -= last_element;
    total_sum /= 2;

    map<int, int> CNT;
    for (int d : drewno)
        CNT[d]++;

    for (auto &el : CNT)
        while (el.second > 2)
        {
            CNT[el.first * 2]++;
            el.second -= 2;
        }

    bitset<A> dp(1);
    for (auto element : CNT)
        for (int i = 1; i <= element.second; i++)
            dp |= dp << element.first;

    int half_sum = 0;

    for (int i = total_sum; i > 0; i--)
        if (dp[i])
        {
            half_sum = i;
            break;
        }

    cout << half_sum + last_element << "\n";
    return 0;
}