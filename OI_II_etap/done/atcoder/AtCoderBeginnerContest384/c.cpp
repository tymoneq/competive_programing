#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

string a[5] = {"A", "B", "C", "D", "E"};

inline bool sorto(pair<int, string> &lhs, pair<int, string> &rhs)
{
    if (lhs.first == rhs.first)
    {
        bool lhsSmaller = 1;
        for (int i = 0; i < 5; i++)
        {
            if (lhs.second.size() == i)
                break;

            if (rhs.second.size() == i)
            {
                lhsSmaller = 0;
                break;
            }

            if (lhs.second[i] > rhs.second[i])
            {
                lhsSmaller = 0;
                break;
            }
            if (lhs.second[i] < rhs.second[i])
            {
                lhsSmaller = 1;
                break;
            }
            if (lhs.second[i] == rhs.second[i])
                continue;
        }

        return lhsSmaller;
    }

    return lhs.first > rhs.first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> A(5);
    vector<pair<int, string>> Res;

    for (int i = 0; i < 5; i++)
        cin >> A[i];

    for (int i = 1; i < 32; i++)
    {
        int sum = 0;
        string s = "";
        for (int j = 0; j < 5; j++)
            if (1 & (i >> j))
            {
                sum += A[j];
                s.append(a[j]);
            }

        Res.push_back({sum, s});
    }

    sort(Res.begin(), Res.end(), sorto);

    for (auto w : Res)
        cout << w.second << "\n";

    return 0;
}