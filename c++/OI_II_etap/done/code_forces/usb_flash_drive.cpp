#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> Size_of_USB(n);
    for (int i = 0; i < n; i++)
        cin >> Size_of_USB[i];
    sort(Size_of_USB.begin(), Size_of_USB.end());
    int head = 0, tail = 0, res = numeric_limits<int>::max(), tmp_res = 0;
    while (head < n)
    {
        if (tmp_res + Size_of_USB[head] < m)
        {
            tmp_res += Size_of_USB[head];
            head++;
        }
        else
        {
            while (tmp_res - Size_of_USB[tail] + Size_of_USB[head] >= m)
            {
                tail++;
                res = min(res, head - tail + 1);

                tmp_res -= Size_of_USB[tail - 1];
            }

            if (tmp_res - Size_of_USB[tail] + Size_of_USB[head] < m)
            {
                res = min(res, head - tail + 1);
            }
            tmp_res += Size_of_USB[head];
            head++;
        }
    }
    cout << res;
    return 0;
}