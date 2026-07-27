#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q; cin >> q;
    vector<int> bylo(q, false);
    priority_queue<pair<int,int>> poly;
    queue<int> mono;
    int idx = 0;
    for(int i = 0; i < q; i++){
        int t; cin >> t;
        if(t == 1){
            int m; cin >> m;
            mono.push(idx);
            poly.push({m,-idx});
            idx++;
        }
        else if(t == 2){
            while(bylo[mono.front()] == true) mono.pop();
            cout << mono.front() + 1 << " ";
            bylo[mono.front()] = true;
            mono.pop();
        }
        else{
            while(bylo[-poly.top().second] == true) poly.pop();
            cout << -poly.top().second + 1 << " ";
            bylo[-poly.top().second] = true;
            poly.pop();
        }
    }
} 