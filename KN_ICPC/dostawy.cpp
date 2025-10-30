#include <bits/stdc++.h>

using namespace std;

constexpr int LIMIT = 10'000'000;

constexpr int base = 1 << 17;
void print(vector<vector<int>> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            printf("%d, ", a[i][j]);
        }
        printf("\n");
    }
}
struct SegmentTree
{
    int n;
    vector<long long> tree, lazy;

    SegmentTree(vector<long long> &arr)
    {
        n = arr.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }

    void build(vector<long long> &arr, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v] = arr[tl];
        }
        else
        {
            int tm = (tl + tr) / 2;
            build(arr, v * 2, tl, tm);
            build(arr, v * 2 + 1, tm + 1, tr);
            tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    void push(int v, int tl, int tr)    {
        if (lazy[v] != 0)
        {
            tree[v] += lazy[v];
            if (tl != tr)
            {
                lazy[v * 2] += lazy[v];
                lazy[v * 2 + 1] += lazy[v];
            }
            lazy[v] = 0;
        }
    }

    void updateRange(int v, int tl, int tr, int l, int r, long long add)
    {
        push(v, tl, tr);
        if (l > r)
            return;
        if (l == tl && r == tr)
        {
            lazy[v] += add;
            push(v, tl, tr);
        }
        else
        {
            int tm = (tl + tr) / 2;
            updateRange(v * 2, tl, tm, l, min(r, tm), add);
            updateRange(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
            tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    long long queryMax(int v, int tl, int tr, int l, int r)
    {
        push(v, tl, tr);
        if (l > r)
            return LLONG_MIN;
        if (l == tl && r == tr)
            return tree[v];
        int tm = (tl + tr) / 2;
        return max(
            queryMax(v * 2, tl, tm, l, min(r, tm)),
            queryMax(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    void add(int pos, long long val)
    {
        updateRange(1, 0, n - 1, pos, pos, val + LIMIT);
        updateRange(1, 0, n - 1, 0, pos - 1, 1);
    }
    void del(int pos, long long val)
    {
        updateRange(1, 0, n - 1, pos, pos, -val - LIMIT);
        updateRange(1, 0, n - 1, 0, pos - 1, -1);
    }

    long long queryMax(int l, int r)
    {
        return queryMax(1, 0, n - 1, l, r);
    }
    void print()
    {
        printf("Tree: ");
        for (int i = 1; i < 4 * n; i++)
        {
            printf("%lld, ", tree[i]);
        }
        printf("\n");
        printf("Lazy: ");
        for (int i = 1; i < 4 * n; i++)
        {
            printf("%d, ", lazy[i]);
        }
        printf("\n");
    }
    void printLeaves(int v = 1, int tl = 0, int tr = -1)
    {
        if (tr == -1)
            tr = n - 1;

        push(v, tl, tr);

        if (tl == tr)
        {
            printf("tree[%d] = %lld, ", tl, tree[v]);
        }
        else
        {
            int tm = (tl + tr) / 2;
            printLeaves(v * 2, tl, tm);
            printLeaves(v * 2 + 1, tm + 1, tr);
        }
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    scanf("%d %d", &n, &q);

    vector<string> m(n);

    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }

    queue<pair<int, int>> que_1;
    queue<pair<int, int>> que_2;
    vector<vector<int>> dys(n, vector<int>(n, -1));
    vector<vector<int>> itr(n, vector<int>(n, -1));

    dys[0][0] = 0;
    que_1.push({0, 0});

    int i = 0;
    while (!que_1.empty())
    {
        auto cur = que_1.front();
        int d = dys[cur.first][cur.second];
        itr[cur.first][cur.second] = i;
        i++;
        if (m[cur.first][cur.second] == 'F')
            que_2.push(cur);
        if (cur.first + 1 < n && m[cur.first + 1][cur.second] != '#' && dys[cur.first + 1][cur.second] == -1)
        {
            dys[cur.first + 1][cur.second] = d + 1;
            que_1.push({cur.first + 1, cur.second});
        }
        if (cur.first - 1 > -1 && m[cur.first - 1][cur.second] != '#' && dys[cur.first - 1][cur.second] == -1)
        {
            dys[cur.first - 1][cur.second] = d + 1;
            que_1.push({cur.first - 1, cur.second});
        }
        if (cur.second + 1 < n && m[cur.first][cur.second + 1] != '#' && dys[cur.first][cur.second + 1] == -1)
        {
            dys[cur.first][cur.second + 1] = d + 1;
            que_1.push({cur.first, cur.second + 1});
        }
        if (cur.second - 1 > -1 && m[cur.first][cur.second - 1] != '#' && dys[cur.first][cur.second - 1] == -1)
        {
            dys[cur.first][cur.second - 1] = d + 1;
            que_1.push({cur.first, cur.second - 1});
        }
        que_1.pop();
    }

    vector<long long> a(i, -LIMIT);
    vector<bool> is_F(i, false);
    SegmentTree tree(a);

    while (!que_2.empty())
    {
        auto cur = que_2.front();
        que_2.pop();
        tree.add(itr[cur.first][cur.second], dys[cur.first][cur.second]);
        is_F[itr[cur.first][cur.second]] = true;
    }

    printf("%d\n", tree.queryMax(0, i - 1));

    for (int j = 0; j < q; j++)
    {
        pair<int, int> cur;
        scanf("%d %d", &cur.first, &cur.second);
        cur.first--;
        cur.second--;
        if (is_F[itr[cur.first][cur.second]])
        {
            tree.del(itr[cur.first][cur.second], dys[cur.first][cur.second]);
            is_F[itr[cur.first][cur.second]] = false;
        }
        else if (!is_F[itr[cur.first][cur.second]])
        {
            tree.add(itr[cur.first][cur.second], dys[cur.first][cur.second]);
            is_F[itr[cur.first][cur.second]] = true;
        }
        printf("%d\n", tree.queryMax(0, i - 1));
    }
    return 0;
}