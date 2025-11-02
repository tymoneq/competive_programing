#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 5e5 + 10;
constexpr int base = 1 << 19;

ll Tree[base << 1];
vector<int> Tree[MAXN];
bool IsOff[MAXN];
map<pair<int, int>, int> TreeIndex;
ll NodeVal[MAXN];
int Sajz[MAXN], Parent[MAXN], NodeTiredness[MAXN];
ll ans = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        NodeTiredness[i] = a;
        TreeIndex[{a, i}] = 0;
    }

    cout << ans << "\n";

    return 0;
}
