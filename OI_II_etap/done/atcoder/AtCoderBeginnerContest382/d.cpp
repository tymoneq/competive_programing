#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> RES;
int n, m;
inline void Generate(vector<int> A)
{
    if (A.size() == n)
    {
        RES.push_back(A);
        return;
    }

    int a = A[A.size() - 1] + 10;
    while (a + (n - 1 - A.size()) * 10 <= m)
    {
        vector<int> ans = A;
        ans.push_back(a);
        Generate(ans);
        a++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int a = 1;
    while (a + (n - 1) * 10 <= m)
    {
        vector<int> ans;
        ans.push_back(a);
        Generate(ans);
        a++;
    }

    cout << RES.size() << '\n';
    for (auto el : RES)
    {
        for (int e : el)
            cout << e << " ";
        cout << '\n';
    }
    return 0;
}