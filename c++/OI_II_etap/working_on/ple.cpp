#include <bits/stdc++.h>

using namespace std;
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> Weight(n);
    for (int i = 0; i < n; i++)
    {
        cin >> Weight[i];
    }
    vector<int> Sum;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (Weight[i] <= Weight[i + 1])
                cout << Weight[i];
        }
    }
    return 0;
}