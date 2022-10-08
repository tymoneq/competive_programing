#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> V(n);
    vector<int> max_rows;
    vector<int> max_cols;
    vector<pair<int, int>> has_value;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            V[i].push_back(a);
        }
    }

    for (int i = 0; i < n; i++)
    {
        int max_row = 0;
        int jj = 0;
        for (int j = 0; j < m; j++)
        {
            if (V[i][j] > max_row)
            {
                max_row = V[i][j];
                jj = j;
            }
        }
        max_rows.push_back(max_row);
        has_value.push_back(make_pair(jj, i));
    }

    for (int i = 0; i < m; i++)
    {
        int max_col = 0;
        for (int j = 0; j < n; j++)
        {
            if (max_col < V[j][i])
            {
                max_col = V[j][i];
            }
        }
        max_cols.push_back(max_col);
    }
    // sort(has_value.begin(), has_value.end());
    //  for (int i = 1; i < has_value.size(); i++)
    //  {
    //      if (has_value[i].first == has_value[i - 1].first)
    //      {
    //          int a = has_value[i].second;
    //          int b = has_value[i - 1].second;
    //          if (max_rows[a] > max_rows[b])
    //          {
    //              max_rows[b] = 0;
    //          }
    //          else if (max_rows[a] < max_rows[b])
    //          {
    //              max_rows[a] = 0;
    //          }
    //          else if (max_rows[a] == max_rows[b])
    //              max_rows[a] = 0;
    //      }
    //  }
    int max_rowww = 0;
    int max_rowww_2 = 0;
    make_heap(max_rows.begin(), max_rows.end());
    max_rowww = max_rows.front();
    pop_heap(max_rows.begin(), max_rows.end());
    max_rowww_2 = max_rows.front();

    int max_col = 0;
    int max_col_2 = 0;
    make_heap(max_cols.begin(), max_cols.end());
    max_col = max_cols.front();
    pop_heap(max_cols.begin(), max_cols.end());
    max_col_2 = max_cols.front();

    if (max_col + max_col_2 > max_rowww + max_rowww_2)
    {
        cout << max_rowww + max_rowww_2 << "\n";
    }
    else if (max_col + max_col_2 <= max_rowww + max_rowww_2)
        cout << max_col + max_col_2 << "\n";
    return 0;
}