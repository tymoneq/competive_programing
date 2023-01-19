#include <bits/stdc++.h>

using namespace std;
bool hasCow[110][110], Vis[110][110];
struct Road
{
    int sr, sc, er, ec;
};
inline bool operator<(const Road &r1, const Road &r2)
{
    return tie(r1.sr, r1.sc, r1.er, r1.ec) < tie(r2.sr, r2.sc, r2.er, r2.ec);
}
vector<pair<int, int>> neighbors(int r, int c)
{
    return {{r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1}};
}
int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fin.open("countcross.in"), fout.open("countcross.out");
    int n, k, R, sr, sc, er, ec, a, b;
    fin >> n >> k >> R;
    set<Road> roads;
    for (int i = 0; i < R; i++)
    {
        fin >> sr >> sc >> er >> ec;
        roads.insert({--sr, --sc, --er, --ec});
        roads.insert({er, ec, sr, sc});
    }
    for (int i = 0; i < k; i++)
    {
        fin >> a >> b;
        a--, b--;
        hasCow[a][b] = 1;
    }
    function<int(int, int, int, int)> connected_cow_num;
    connected_cow_num = [&](int r, int c, int prev_r, int prev_c) -> int
    {
        if (r < 0 || c < 0 || r >= n || c >= n || Vis[r][c] || roads.count(Road{r, c, prev_r, prev_c}))
            return 0;
        Vis[r][c] = 1;
        int cow_num = hasCow[r][c];
        for (const auto &[nr, nc] : neighbors(r, c))
            cow_num += connected_cow_num(nr, nc, r, c);
        return cow_num;
    };
    vector<int> cow_components;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            if (!Vis[r][c])
            {
                int comp = connected_cow_num(r, c, r, c);
                if (comp != 0)
                    cow_components.push_back(comp);
            }

    int res = 0;
    for (int i = 0; i < cow_components.size(); i++)
        for (int j = i + 1; j < cow_components.size(); j++)
            res += cow_components[i] * cow_components[j];

    fout << res;
    fin.close(), fout.close();
    return 0;
}