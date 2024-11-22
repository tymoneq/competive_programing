#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &a : A)
        cin >> a;

    int res = 0;
    set<int> used;

    int l = 0, r = 0;
    while (r < n - 1)
    {
        if (A[r] == A[r + 1] && !used.count(A[r]))
        {

            r++;
            res = max(res, (int)used.size() + 1);
            while (r < n - 1)
            {
                if (A[r + 1] == A[r])
                {
                    l = r - 1;
                    r++;
                    used.clear();
                }
                else
                    break;
            }
            used.insert(A[r]);
        }

        else if (A[r] == A[r + 1] && used.count(A[r]))
        {
            while (used.count(A[r]) && l < r)
            {
                if (used.count(A[l]) && A[l] == A[l + 1])
                {
                    used.erase(A[l]);
                    while (A[l] == A[l + 1] && l < r)
                        l++;
                }
                l++;
            }
            r++;
            res = max(res, (int)used.size() + 1);
            while (r < n - 1)
            {
                if (A[r + 1] == A[r])
                {
                    l = r - 1;
                    r++;
                    used.clear();
                }
                else
                    break;
            }

            used.insert(A[r]);
        }

        else
            used.clear();

        res = max(res, (int)used.size());
        r++;
    }

    cout << res * 2 << "\n";
    return 0;
}