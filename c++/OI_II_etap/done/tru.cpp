#include <bits/stdc++.h>
using namespace std;

struct val
{
    int val = 0;
    int index_1 = 0;
    int index_2 = 0;
};
inline bool sort_Res(vector<int> &lhs, vector<int> &rhs) { return lhs.size() > rhs.size(); }

int main()
{
    int n;
    val max_val;
    int to_remove = 0;
    cin >> n;
    vector<vector<int>> Res(n);
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            if (j <= n)
                Res[j - 1].push_back(i);

    sort(Res.begin(), Res.end(), sort_Res);
    for (int i = 0; i < n - 1; i++)
    {
        if (max_val.val >= Res[i].size() + Res[i + 1].size())
            break;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (max_val.val >= Res[i].size() + Res[j].size())
                break;
            for (int num : Res[j])
                if (binary_search(Res[i].begin(), Res[i].end(), num))
                    to_remove++;
            if (max_val.val < Res[i].size() + Res[j].size() - to_remove)
            {
                max_val.val = Res[i].size() + Res[j].size() - to_remove;
                max_val.index_1 = i;
                max_val.index_2 = j;
            }
            to_remove = 0;
        }
    }
    if (max_val.val == 0)
        cout << 1 << "\n"
             << 1 << " " << 1;
    else
        cout << max_val.val << "\n"
             << Res[max_val.index_1][Res[max_val.index_1].size() - 1] << " " << Res[max_val.index_2][Res[max_val.index_2].size() - 1];
    return 0;
}