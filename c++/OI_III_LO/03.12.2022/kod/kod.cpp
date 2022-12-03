#include <bits/stdc++.h>

using namespace std;
inline bool sorto(int &lhs, int &rhs) { return lhs > rhs; }
inline bool sortoo(pair<int, int> &lhs, pair<int, int> &rhs)
{
    if (lhs.first < rhs.first)
        return true;
    if (lhs.first == rhs.first && lhs.second < rhs.second)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> Res(n - 1);
    vector<int> Vertex(n - 2);
    vector<int> Sort_vertex(n - 2);
    vector<int> num(n);
    vector<int> odp;
    for (int i = 1; i <= n; i++)
        num[i - 1] = i;
    for (int i = 0; i < n - 2; i++)
    {
        int a;
        cin >> a;
        Vertex[i] = a;
        Sort_vertex[i] = a;
    }
    sort(Sort_vertex.begin(), Sort_vertex.end(), sorto);
    if (Sort_vertex[Sort_vertex.size() - 1] > 1)
        for (int j = 1; j < Sort_vertex[Sort_vertex.size() - 1]; j++)
            odp.push_back(j);
    for (int i = Sort_vertex.size() - 1; i >= 0; i--)
    {
        if (i == 0)
            for (int j = Sort_vertex[0] + 1; j <= n; j++)
                odp.push_back(j);
        else if (Sort_vertex[i - 1] - Sort_vertex[i] > 1)
            for (int j = Sort_vertex[i] + 1; j < Sort_vertex[i - 1]; j++)
                odp.push_back(j);
    }
    int index = 0;
    for (int i = 0; i < n - 2; i++)
    {
        int tmp = odp[index];
        int mini = numeric_limits<int>::max();
        for (int j = 0; j < i; j++)
        {
            auto it = lower_bound(num.begin(), num.end(), Vertex[j]);
            if (Vertex[j] < tmp && Vertex[j] != Vertex[i] && Vertex[j] == *it)
                mini = Vertex[j];
        }

        if (mini < odp[index])
        {
            tmp = mini;
            index -= 1;
        }

        auto itr = lower_bound(num.begin(), num.end(), tmp);
        Res[i] = make_pair(min(Vertex[i], *itr), max(Vertex[i], *itr));
        index++;
        num.erase(itr);
    }
    for (int i = 0; i < num.size() - 1; i++)
        Res[Vertex.size() + i] = make_pair(min(num[i], num[i + 1]), max(num[i], num[i + 1]));

    sort(Res.begin(), Res.end(), sortoo);
    for (int i = 0; i < n - 1; i++)
    {
        cout << Res[i].first << " " << Res[i].second << "\n";
    }
    return 0;
}