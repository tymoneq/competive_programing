#include <bits/stdc++.h>
using namespace std;
struct distances_between
{
    int licz = 0;
    int mian = 0;
    int left = 0;
    int right = 0;
};
void lower(distances_between &el)
{
    while (el.licz % 2 == 0 && el.mian != 1)
    {
        el.licz /= 2;
        el.mian /= 2;
    }
}
int Euklides(int a, int b)
{
    int tmp;
    while (a != b && b != 0 && a != 0)
    {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}
inline int NWW(int a, int b) { return a * b / Euklides(a, b); }
bool soto(distances_between &lhs, distances_between &rhs)
{
    int nww = NWW(lhs.mian, rhs.mian);
    int l_m = nww / lhs.mian;
    int r_m = nww / rhs.mian;
    if (lhs.licz * l_m < rhs.licz * r_m)
        return true;
    else if (lhs.licz * l_m == rhs.licz * r_m && lhs.left < rhs.left)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, X, z;
    cin >> n >> X >> z;
    vector<int> position(n); // wczytanie danych
    vector<distances_between> heap;
    for (int i = 0; i < n; i++)
    {
        cin >> position[i];
        if (i != 0 || (i == n - 1 && position[i] == X))
        {
            distances_between ds_b;
            ds_b.licz = position[i] - position[i - 1];
            ds_b.mian = 2;
            ds_b.left = position[i - 1];
            ds_b.right = position[i];
            lower(ds_b);
            heap.push_back(ds_b);
        }
        else if (i == n - 1)
        {
            distances_between ds_b;
            ds_b.licz = position[i] - position[i - 1];
            ds_b.mian = (position[i] - position[i - 1]) % 2;
            ds_b.left = position[i];
            ds_b.right = 0;
            lower(ds_b);
            heap.push_back(ds_b);
        }
    }
    make_heap(heap.begin(), heap.end(), soto);
    vector<pair<int, int>> res;
    for (int i = 0; i < z; i++)
    {
        int a;
        cin >> a;
        if (a <= res.size())
            cout << res[a - 1].first << "/ " << res[a - 1].second << "\n";
        else
        {
            for (int j = 0; j < a - res.size(); j++)
            {
                // distances_between ds_b = pq.top();
                // pq.pop();
                // distances_between ds_left;
                // distances_between ds_right;
                // ds_left.dist = ds_b.dist / 2;
                // ds_left.left = ds_b.left;
                // ds_left.right = ds_b.left + ds_b.dist;
                // ds_right.dist = ds_b.dist / 2;
                // ds_right.left = ds_b.left + ds_b.dist;
                // ds_right.right = ds_b.right;
                // pq.push(ds_right);
                // pq.push(ds_left);
                // res.push_back(ds_b.left + ds_b.dist);
            }
            cout << res[a - 1].first << "/ " << res[a - 1].second << "\n";
        }
    }

    return 0;
}