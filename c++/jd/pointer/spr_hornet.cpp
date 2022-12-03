#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double n;
    cin >> n;
    vector<double> W(n + 1, 0);
    for (int i = 0; i <= n; i++)
        cin >> W[i];

    int x;
    cin >> x;
    reverse(W.begin(),W.end());
    double tmp = x * W[0] + W[1];
    for (int i = 2; i <= n; i++)
        tmp = tmp * x + W[i];

    cout << tmp;
    return 0;
}