#include <bits/stdc++.h>

using namespace std;
const int M = 1e5+10;
vector<int> Graph[M];
bool Vis[M];
int Dist[M];
int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fin.open("lasers.in"), fout.open("lasers.out");
    int n;
    fin >> n;
    vector<pair<int, int>> V(n + 2);
    unordered_map<int, vector<int>> lines[2];
    for (int i = 0; i < n + 2; i++)
    {
        fin >> V[i].first >> V[i].second;
        lines[0][V[i].first].push_back(i);
        lines[1][V[i].second].push_back(i);
    }
    queue<pair<int, bool>> q;
    q.push({0, 1});
    q.push({0, 0});
    Vis[0] = 1;
    int v;
    bool beamdir;
    while (!q.empty())
    {
        v = q.front().first;
        beamdir = q.front().second;
        q.pop();
        int dir = (beamdir ? 0 : 1);
        int coord = (beamdir ? V[v].first : V[v].second);
        for (int w : lines[dir][coord])
            if (!Vis[w])
            {
                q.push({w, !beamdir});
                Vis[w] = 1;
                Dist[w] = Dist[v] + 1;
            }
    }
    fout << Dist[1] - 1;

    fin.close(), fout.close();
    return 0;
}