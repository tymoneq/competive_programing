#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>,
                  rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    int N;
    cin >> N;
    Tree<int> T;
    vector<int> last_oc(N + 1, -1);
    int64_t ans = 0;
    for (int i = 0; i < N; ++i)
    {
        int b;
        cin >> b;
        ans += T.size() - T.order_of_key(last_oc[b] + 1);
        T.insert(i);
        if (last_oc[b] != -1)
            T.erase(last_oc[b]);
        last_oc[b] = i;
    }
    cout << ans << "\n";
}