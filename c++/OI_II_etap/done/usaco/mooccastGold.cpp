#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e15;
vector<pair<int, double>> Graph[1010];
double Dist[1010];
bool Vis[1010];
int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.open("moocast.in"), fout.open("moocast.out");
    int n;
    fin >> n;
    vector<pair<int, int>> Cows(n);
    for (int i = 0; i < n; i++)
        fin >> Cows[i].first >> Cows[i].second;
    for (int i = 0; i <= n; i++)
        Dist[i] = INF; // seting dist to INF
    double d = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) 
        {
            // Calculating distance from i cow to j cow and creating weighted graph
            d = sqrt(pow(Cows[j].first - Cows[i].first, 2) + pow(Cows[j].second - Cows[i].second, 2));
            Graph[i].push_back({j, d});
            Graph[j].push_back({i, d});
        }

    // Dijkstra algorythm
    pair<double, int> v;
    double weight = 0;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    Dist[0] = 0;
    pq.push({0, 0});
    while (!pq.empty())
    {
        v = pq.top();
        pq.pop();
        for (auto w : Graph[v.second])
            if (!Vis[w.first])
            {
                weight = max(v.first, w.second);
                if (Dist[w.first] > weight)
                {
                    Dist[w.first] = weight;
                    pq.push({weight, w.first});
                }
            }

        Vis[v.second] = 1;
    }
    double res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, Dist[i]); // finding max distance
    long long tmp = 0;
    res = res * res;
    tmp = res * 10;
    long long r = res;
    if (tmp % 10 == 9)
        r++;

    fout << r;
    fin.close(), fout.close();
    return 0;
}