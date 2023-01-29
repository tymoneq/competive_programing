#include <bits/stdc++.h>

using namespace std;

inline bool sorto(pair<int, int> &lhs, pair<int, int> &rhs)
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
    int n, a, b;
    cin >> n;
    vector<pair<int, int>> Exams(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        Exams[i] = make_pair(a, b);
    }
    sort(Exams.begin(), Exams.end(), sorto);
    int res = Exams[0].second;
    for (int i = 1; i < n; i++)
    {
        if (Exams[i].second >= res)
            res = Exams[i].second;
        else if (Exams[i].first >= res)
            res = Exams[i].first;
    }
    cout << res;
    return 0;
}