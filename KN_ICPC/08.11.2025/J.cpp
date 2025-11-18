#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        ll N;
        cin >> N;

        ll power = 1;
        int dl = 1;
        while (power * 10 < N)
        {
            power *= 10;
            dl++;
        }
        vector<int> Shifted;
        Shifted.push_back(N);

        int tmp = N;

        for (int i = 1; i < dl; i++)
        {
            int lastNum = tmp % 10;
            tmp /= 10;
            tmp += lastNum * power;
            Shifted.push_back(tmp);
        }

        vector<int> ans;

        for (int i = 1; i < Shifted.size(); i++)
        {
            int x = Shifted[i] - N;

            if (x < 1)
                continue;

            if (x % dl == i)
                ans.push_back(x);
        }

        sort(ans.begin(), ans.end());
        cout << ans.size() << "\n";

        for (int a : ans)
            cout << a << " ";

        cout << "\n";
    }

    return 0;
}