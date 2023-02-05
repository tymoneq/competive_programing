#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> B(n);
    for (int i = 0; i < n; i++)
        cin >> B[i];
    sort(B.begin(), B.end());
    int glowa = 2, ogon = 0, wyn = 0;
    while (glowa < n)
    {
        if (ogon + 2 > glowa)
        {
            glowa++;
            continue;
        }
        if (B[ogon] + B[ogon + 1] > B[glowa])
        {
            wyn = max(wyn, glowa - ogon + 1);
            glowa++;
            continue;
        }
        ogon++;
    }
    cout << wyn;
    return 0;
}