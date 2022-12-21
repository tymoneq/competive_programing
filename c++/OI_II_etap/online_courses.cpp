#include <bits/stdc++.h>
using namespace std;

const int MAX_VAL = 10;

vector<int> Graph[MAX_VAL];
int sto[MAX_VAL];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, a, b, w, h = 0, min_index = 0;
    cin >> n >> k;
    vector<int> Main_courses(k);
    vector<int> res;
    for (int i = 0; i < k; i++)
        cin >> Main_courses[i];

    sort(Main_courses.begin(), Main_courses.end());
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        for (int j = 0; j < a; j++)
        {
            cin >> b;
            Graph[i].push_back(b);
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
        for (int v : Graph[i])
            sto[v]++;

    for (int i = 1; i <= n; i++)
    {
        if (i == Main_courses[h] && sto[i] == 0 && Graph[i].size() != 0)
        {
            min_index = i;
            break;
        }
        if (i == Main_courses[h])
            h++;
    }
    for (int i = 1; i <= n; i++)
        sto[i] = 0;

    q.push(min_index);
    while (!q.empty())
    {
        w = q.front();
        q.pop();
        for (int v : Graph[w])
        {
            q.push(v);
            sto[v] += 1;
        }
    }
    q.push(min_index);
    while (!q.empty())
    {
        w = q.front();
        q.pop();
        res.push_back(w);
        for (int v : Graph[w])
        {
            sto[v]--;
            if (sto[v] == 0)
                q.push(v);
        }
    }
    cout << res.size() << "\n";
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i] << " ";

    return 0;
}