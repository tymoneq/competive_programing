#include <bits/stdc++.h>
using namespace std;

const int MAX_VAL = 1e5 + 10;

vector<int> Graph[MAX_VAL];
int color[MAX_VAL];
int Main_courses[MAX_VAL];
vector<int> res;
bool cycle = false;
void Find_cycle(int u)
{
    if (color[u] == 0)
    {
        color[u] = 1;
        for (int to : Graph[u])
            Find_cycle(to);
        color[u] = 2;
        res.push_back(u);
    }
    else if (color[u] == 1)
        cycle = true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, a, b, w;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> Main_courses[i];

    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        for (int j = 0; j < a; j++)
        {
            cin >> b;
            Graph[i].push_back(b);
        }
    }
    for (int i = 0; i < k; i++)
        Find_cycle(Main_courses[i]);
    if (cycle)
    {
        cout << -1;
        return 0;
    }
    cout << res.size() << "\n";
    for (int el : res)
        cout << el << ' ';
    return 0;
}