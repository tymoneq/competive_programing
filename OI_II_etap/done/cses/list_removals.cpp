#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
constexpr int M = 2e5 + 10;
int Arr[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a;
    Tree<int> ist;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ist.insert(i);
        cin >> Arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        a--;
        int pos = *ist.find_by_order(a);
        cout << Arr[pos] << " ";
        ist.erase(pos);
    }

    return 0;
}