#include<bits/stdc++.h>

using namespace std;

constexpr int base = 1 << 19;

struct node{
    int val = -1;
    int idx = -1;
};

vector<node> tree(2*base);

void upd(int x, int val, int idx){
    x += base;

    tree[x].val = val;
    tree[x].idx = idx;
    x /= 2;
    while(x){
        if(tree[x*2].val > tree[x*2 + 1].val){
            tree[x] = tree[x*2];
        }
        else if(tree[x*2].val <= tree[x*2 + 1].val){
            tree[x] = tree[x*2 + 1];
        }
        x /= 2;
    }
}

node query(int x){
    int l = base;
    int r = base + x;
    node res;
    while(l <= r && l != 0 && r != 0){
        if(l%2 == 1){
            if(res.val < tree[l].val) res = tree[l];
            else if(res.val == tree[l].val && res.idx < tree[l].idx) res = tree[l];
        }
        if(r%2 == 0){
            if(res.val < tree[r].val) res = tree[r];
            else if(res.val == tree[r].val && res.idx < tree[r].idx) res = tree[r];
        }
        l = (l + 1)/2;
        r = (r - 1)/2;
    }
    return res;
}
void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    vector<int> lisIdx(n);
    vector<int> lisLen(n);
    for(int i = 0; i < n; i++){
        node res = query(a[i]);
        if(res.val == -1){
            lisIdx[i] = -1;
            lisLen[i] = 1;
        }
        else{
            lisIdx[i] = res.idx;
            lisLen[i] = res.val;
        }
        upd(a[i], lisLen[i], i);
    }
    int maxx = 0;
    int maxxw = -1;
    for(int i = 0; i < n; i++){
        cout << lisIdx[i] << " ";
        if(lisLen[i] > maxx){
            maxx = lisLen[i];
            maxxw = a[i];
        }
        else if(lisLen[i] == maxx){
            if(a[i] < maxxw) maxxw = a[i];
        }
    }
    cout << endl;
    vector<int> LIS;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] == maxxw){
            LIS.push_back(i);
            break;
        }
    }
    int akt = LIS.back();
    while(akt != -1){
        akt = lisIdx[akt];
        LIS.push_back(akt);
    }
    for(int u : LIS) cout << u << " ";
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}