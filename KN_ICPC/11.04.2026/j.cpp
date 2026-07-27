#include <bits/stdc++.h>
#include <ios>
#include <vector>

using namespace std;

const int maxn = 2e5 + 7;
vector<int> par(maxn);

int findd(int v){
    if(par[v] == v) return v;
    par[v] = findd(par[v]);
    return par[v];
}

void uni(int a, int b){
    a = findd(a);
    b = findd(b);
    if(a != b) par[a] = b;
}

inline void solve() {
    int n,m,k; cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) par[i] = i;
    vector<pair<int,pair<int,int>>> edges(m);
    for(int i = 0; i < m; i++){
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first; 
        if(edges[i].first < k) edges[i].first *= -1;
        else edges[i].first = edges[i].first - k;
    }
    sort(edges.begin(), edges.end());
    int maxx = 0;
    long long sum = 0;
    int smallest_bigger = 1e9 + 7;
    for(int i = 0; i < m; i++){
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        int cost = edges[i].first;
        if(findd(a) == findd(b)){
            if(cost >= 0) smallest_bigger = min(smallest_bigger, cost);
            continue;
        }
        else{
            if(cost < 0) maxx = max(maxx, -cost);
            else{
                maxx = max(maxx, k + cost);
                sum += cost;
            }
            uni(a,b);
        }
    }
    if(maxx < k){
        sum = min(smallest_bigger, k - maxx);
    }
    cout << sum << "\n";
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}