#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
const int INF = 1e9 + 1;

struct SegmentTree
{
    struct Node
    {
        int L, minVal, maxVal, lazy;
        Node() : L(0), minVal(INF), maxVal(-INF), lazy(0) {}
    };

    vector<Node> tree;
    int n;

    SegmentTree(int size) : n(size)
    {
        tree.resize(4 * n);
    }

    void push(int v, int tl, int tr)
    {
        if (tree[v].lazy != 0)
        {
            tree[v].minVal += tree[v].lazy;
            tree[v].maxVal += tree[v].lazy;

            if (tl != tr)
            {
                tree[2 * v].lazy += tree[v].lazy;
                tree[2 * v + 1].lazy += tree[v].lazy;
            }

            tree[v].lazy = 0;
        }
    }

    void build(const vector<int> &a, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v].L = 1;
            tree[v].minVal = tree[v].maxVal = a[tl];
        }
        else
        {
            int tm = (tl + tr) / 2;
            build(a, 2 * v, tl, tm);
            build(a, 2 * v + 1, tm + 1, tr);
            merge(v);
        }
    }

    void merge(int v)
    {
        tree[v].L = tree[2 * v].L + tree[2 * v + 1].L;
        tree[v].minVal = min(tree[2 * v].minVal, tree[2 * v + 1].minVal);
        tree[v].maxVal = max(tree[2 * v].maxVal, tree[2 * v + 1].maxVal);
    }

    void update_range(int v, int tl, int tr, int l, int r, int addend)
    {
        push(v, tl, tr);
        if (l > r)
            return;
        if (l == tl && r == tr)
        {
            tree[v].lazy += addend;
            push(v, tl, tr);
        }
        else
        {
            int tm = (tl + tr) / 2;
            update_range(2 * v, tl, tm, l, min(r, tm), addend);
            update_range(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, addend);
            merge(v);
        }
    }

    int count_in_range(int v, int tl, int tr, int l, int r, int a, int b)
    {
        push(v, tl, tr);
        if (l > r || tree[v].minVal > b || tree[v].maxVal < a)
            return 0;
        if (l == tl && r == tr && tree[v].minVal >= a && tree[v].maxVal <= b)
        {
            return tree[v].L;
        }
        int tm = (tl + tr) / 2;
        return count_in_range(2 * v, tl, tm, l, min(r, tm), a, b) +
               count_in_range(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, a, b);
    }

    int find_kth_smallest(int v, int tl, int tr, int k)
    {
        push(v, tl, tr);
        if (tl == tr)
            return tl;
        int tm = (tl + tr) / 2;
        push(2 * v, tl, tm);
        if (tree[2 * v].L >= k)
        {
            return find_kth_smallest(2 * v, tl, tm, k);
        }
        else
        {
            return find_kth_smallest(2 * v + 1, tm + 1, tr, k - tree[2 * v].L);
        }
    }

    void increase_k_minimum(int k)
    {
        int idx = find_kth_smallest(1, 0, n - 1, k);
        int x = tree[1].minVal;

        update_range(1, 0, n - 1, 0, idx - 1, 1);                      // increase all less than x
        int countLess = count_in_range(1, 0, n - 1, 0, idx - 1, x, x); // count how many equal x
        update_range(1, 0, n - 1, idx, idx + k - countLess - 1, 1);    // increase k-countLess numbers equal x
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    SegmentTree segTree(n);
    segTree.build(a, 1, 0, n - 1);

    for (int i = 0; i < m; ++i)
    {
        string type;
        cin >> type;
        if (type[0] == 'z')
        {
            int a, b;
            cin >> a >> b;
            cout << segTree.count_in_range(1, 0, n - 1, 0, n - 1, a, b) << "\n";
        }
        else
        {
            int k;
            cin >> k;
            segTree.increase_k_minimum(k);
        }
    }

    return 0;
}
