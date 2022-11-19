#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    //cin >> n;
    vector<int> Tab = {0, 3, 5, 6, 9, 12, 17, 20};
    // for (int i = 0; i < n; i++)
    // {
    //     // int a;
    //     // cin >> a;
    //     // if (a <= 6)
    //     //     cout << Tab[a - 1] << "\n";
    //     // else
    //     {
            for (int j = 0; j <= 1000; j++)
            {
                if (3 * j % 21 != 0)
                    cout << 3 * j << " ";
                if ((3 * j + 1) % 2 == 0 && 3 * j % 21 != 0)
                    cout << 3 * j + 1 << " ";
            }
        //}
    // }
    return 0;
}