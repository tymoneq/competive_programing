#include <bits/stdc++.h>

using namespace std;
constexpr int M = 1e5 + 10;
int Nums[M], Val[M], Path[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> Nums[i];
    Val[n - 1] = 1, Path[n - 1] = n - 1;
    pair<int, int> mx;
    for (int i = n - 2; i >= 0; i--)
    {
        mx.first = 0;
        mx.second = i;
        for (int j = i + 1; j < n; j++)
            if (Nums[j] > Nums[i] && mx.first < Val[j])
            {
                mx.first = Val[j];
                mx.second = j;
            }
        Val[i] = mx.first + 1;
        Path[i] = mx.second;
    }
    int MX = 0;
    for (int i = 0; i < n; i++)
        MX = max(MX, Val[i]);
    set<int> Res;
    int jmp = 0;
    for (int i = 0; i < n; i++)
        if (Val[i] == MX)
        {
            Res.insert(Nums[i]);
            jmp = Path[i];
            while (jmp != Path[jmp])
            {
                Res.insert(Nums[jmp]);
                jmp = Path[jmp];
            }
            Res.insert(Nums[jmp]);
        }

    cout << Res.size() << "\n";
    for (int w : Res)
        cout << w << " ";
    return 0;
}