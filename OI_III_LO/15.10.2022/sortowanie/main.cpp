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
    cout.tie(0);
    int n, wynik = 0, num;
    cin >> n;
    vector<pair<int, int>> data(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        data[i] = make_pair(num, i);
    }
    sort(data.begin(), data.end(), sorto);
    for (int i = 0; i < n; i++)
        if (data[i].second % 2 != i % 2)
            wynik++;
    cout << wynik / 2;
    return 0;
}