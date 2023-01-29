#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int sum = 0;
    vector<int> V(n);
    for (int i = 0; i < n; i++)
    {
        cin >> V[i];
        sum += V[i];
    }
    vector<char> Res;
    for (int i = 0; i < n; i++)
        Res.push_back('R');
    int cost = 0;
    int last = n - 1;
    int firs = n - 2;
    if (sum == 1)
        Res.push_back('L');
    while (Res.size() < sum)
    {

        Res.push_back('L');
        while (V[firs] >= V[last] && firs >= 0)
        {
            firs--;
            Res.push_back('L');
        }
        if (V[last] - 2 > 0)
        {
            int tmp = (V[last] - 2) / 2;
            if ((V[last] - 2) % 2 == 1)
                tmp;
            for (int i = 0; i < tmp; i++)
            {
                for (int j = firs; j < last; j++)
                    Res.push_back('R');
                for (int j = last; j > firs; j--)
                    Res.push_back('L');
            }
            if ((V[last] - 2) % 2 == 1)
                Res.push_back('R'), Res.push_back('L');
        }
        cost = V[last];
        for (int i = last; i > firs; i--)
            V[i] -= cost;
        for (int i = last - 1; i >= 0; i--)
        {
            if (V[i] < V[last])
            {
                cost = 0;
                last = i;
                firs = last - 1;
                break;
            }
            if (V[i] > V[last])
            {
                cost = 0;
                last = i;
                firs = last - 1;
                break;
            }
        }
    }

    for (char z : Res)
        cout << z;
    return 0;
}