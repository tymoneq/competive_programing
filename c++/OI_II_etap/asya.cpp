#include <bits/stdc++.h>
using namespace std;
const int M = 1.5e5 + 10;
vector<int> Graph[M];
bool Visit[M];
int St[M];
vector<int> res;
inline void Find_cycle(int v)
{
    Visit[v] = 1;
    res.push_back(v);
    for (int w : Graph[v])
        if (!Visit[w])
            Find_cycle(w);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, b, mx = numeric_limits<int>::max(), mx_index = 0;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
        St[a] += 1;
        St[b] += 1;
    }
    for (int i = 1; i <= n; i++)
        if (mx > St[i])
        {
            mx = St[i];
            mx_index = i;
        }

    Find_cycle(mx_index);
    for (int el : res)
        cout << el << " ";
    return 0;
}