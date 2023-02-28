#include <bits/stdc++.h>
using namespace std;
constexpr int M = 100010;
vector<int> Tree[M];
double res;
void dfs(int v, int p, int d, double current_probability)
{
    int possible_move = 0;
    for (int w : Tree[v])
        if (w != p)
            possible_move++;
    if (!possible_move)
        res += d * current_probability;
    else
    {
        double new_probability = current_probability / possible_move;
        for (int w : Tree[v])
            if (w != p)
                dfs(w, v, d + 1, new_probability);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, b;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        Tree[a].push_back(b), Tree[b].push_back(a);
    }
    dfs(1, 1, 0, 1);
    cout << fixed << setprecision(20) << res;
    return 0;
}