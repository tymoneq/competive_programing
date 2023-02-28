#include <bits/stdc++.h>

using namespace std;
constexpr int M = 2e5 + 10;
bool Used[M];
int Nums[M];
vector<int> Res[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, number_of_used = 0, mn = 0, r = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> Nums[i];
    while (number_of_used < n)
    {
        mn = 0;
        for (int i = 0; i < n; i++)
            if (!Used[i] && Nums[i] > mn)
            {
                Used[i] = 1;
                mn = Nums[i];
                Res[r].push_back(mn);
                number_of_used++;
            }
        r++;
    }
    for (int i = 0; i < r; i++)
    {
        for (int w : Res[i])
            cout << w << " ";
        cout << "\n";
    }
    return 0;
}