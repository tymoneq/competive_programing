#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    ll res = 0;

    cin >> N >> M;
    vector<int> A(N);
    for (int &a : A)
        cin >> a;

    // for (int i = 0; i < N; i++)
    // {
    //     ll tmp = 0;
    //     for (int j = i; j < N; j++)
    //     {
    //         tmp += A[j];
    //         res += tmp % M;
    //     }
    // }

    ll sum = 0;
    for (int i = 0; i < N; i++)
        sum += (A[i] * (N - i));

    res += sum % M;

    for (int i = 0; i < N; i++)
    {
        sum -= (A[i] * (N - i));
        res += sum % M;
    }

    cout << res << "\n";
    return 0;
}