#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    int N, K;
    cin >> N >> K;
    long long answer = 2019201997LL - 48LL * N - 84LL * (K - 1LL);
    cout << answer << endl;
}