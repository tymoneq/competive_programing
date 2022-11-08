#include <bits/stdc++.h>
 
using namespace std;
 
const int infty = numeric_limits<int>::max(); // uwaga na limit
int n, m;
vector< pair<int,int> > graf[100000];
 
vector<int> waga;
 
struct cmp
{
    // czy a jest mniejsze od b
    bool operator() (const int& a, const int& b)
    {
        if (waga[a] < waga[b]) return true;
        if (waga[a] > waga[b]) return false;
        return a<b;
    }
};
 
 
set<int, cmp> kopiec; 
 
 
void dijkstra(int s)
{
    int v, u, c;
    waga.clear(); // kasuje wektor
    waga.resize(n, infty); //
 
    waga[s] = 0;
    kopiec.clear();
    kopiec.insert(s);
 
    while( !kopiec.empty() )
    {
        u = *(kopiec.begin());
        kopiec.erase(kopiec.begin());
 
        for (int i=0; i<graf[u].size(); i++)
        {
            v = graf[u][i].first;
            c = graf[u][i].second;
            if (waga[u]+c < waga[v])
            {
                // uaktualniamy wagę wierzchołka v
                kopiec.erase(kopiec.find(v));
                waga[v] = waga[u]+c;
                kopiec.insert(v);
            }
        }
    }
}
 
int main(void)
{
    int a,b,c, s,t;
 
    cin >> n >> m;
    for (int i=0; i<m; i++)
    {
        cin >> a >> b >> c; // c = koszt krawędzi od a do b
        graf[a].push_back( pair<int,int>(b,c) );
    }
 
    cin >> s >> t; // s - źródło, t - wierzchołek, do którego najkrótszej odległości szukamy
 
    dijkstra(s); // alg. Dijkstry wypełni całą tablicę waga[..] najkrótszymi odległościami
    cout << waga[t];
    return 0;
}