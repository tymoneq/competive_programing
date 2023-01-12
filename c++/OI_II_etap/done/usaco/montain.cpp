#include <bits/stdc++.h>
using namespace std;
inline bool sorto(pair<int, int> &lhs, pair<int, int> &rhs)
{
    if (lhs.first == rhs.first)
        return lhs.second > rhs.second;
    return lhs.first < rhs.first;
}
int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("mountains.in"), fout.open("mountains.out");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fin.tie(0);
    fout.tie(0);
    int n, x, y;
    fin >> n;
    vector<pair<int, int>> Mountain(n);
    for (int i = 0; i < n; i++)
    {
        fin >> x >> y;
        Mountain[i].first = x - y, Mountain[i].second = x + y;
    }

    sort(Mountain.begin(), Mountain.end(), sorto);
    int res = 0, mx = -1;
    for (int i = 0; i < n; i++)
        if (Mountain[i].second > mx)
        {
            mx = Mountain[i].second;
            res++;
        }

    fout << res;
    fin.close(), fout.close();
    return 0;
}