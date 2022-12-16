#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int MAX_VAL = 20;

ll Posiotion[MAX_VAL];
int Height[MAX_VAL];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, H1, H2, l = 0, r = 1;
    ll N1, N2, res = 0, tmp_res = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> Posiotion[i] >> Height[i];
    cin >> N1 >> H1 >> N2 >> H2;
    if (H1 < H2)
    {
        ll tmp_1 = H1, tmp_2 = N1;
        N1 = N2;
        H1 = H2;
        H2 = tmp_1;
        N2 = tmp_2;
    }
    return 0;
}