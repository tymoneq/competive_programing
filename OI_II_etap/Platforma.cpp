#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double res;
    int n, q, a, mid;
    cin >> n >> q;
    vector<int> El;
    if (q <= 200)
        for (int i = 0; i < q; i++)
        {
            cin >> a;
            El.push_back(a);
            sort(El.begin(), El.end());
            mid = El.size() / 2;
            if (El.size() % 2 == 0)
            {
                res = El[mid] + El[mid - 1];
                res /= 2;
            }

            else
                res = El[mid];
            cout << fixed << setprecision(1) << res << "\n";
        }
    else
        for (int i = 0; i < q; i++)
        {
            cin >> a;
            El.push_back(a);
            mid = El.size() / 2;
            if (El.size() % 2 == 0)
            {
                res = El[mid] + El[mid - 1];
                res /= 2;
            }
            else
                res = El[mid];
            cout << fixed << setprecision(1) << res << "\n";
        }
    return 0;
}