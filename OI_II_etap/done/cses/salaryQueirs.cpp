#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int n, q, arr[200001];
const int MOD = 1000000007;
Tree<pair<int, int>> T;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, x, y;
    cin >> n >> q;
    char z;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        T.insert({arr[i], i});
    }
    for (int i = 0; i < q; i++)
    {
        cin >> z >> x >> y;
        if (z == '!')
        {
            T.erase({arr[x], x});
            arr[x] = y;
            T.insert({arr[x], x});
        }
        else
            cout << T.order_of_key({y, MOD}) - T.order_of_key({x - 1, MOD}) << "\n";
    }
    return 0;
}
