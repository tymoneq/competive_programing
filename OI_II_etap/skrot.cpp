#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);

    int N = 3000, n = 20;
    vector<int> A(N), B(n), Ans;
    int res = 0;
    map<int, int> M;

    for (int &a : A)
    {
        cin >> a;
        M[a]++;
    }
    for (int &b : B)
        cin >> b;

    sort(A.begin(), A.end(), greater<int>());

    for (int a : A)
    {
        bool T = 0;
        for (int j : B)
            if (j % a == 0)
            {
                T = 1;
                break;
            }

        if (T)
            ++res;
    }
    for (int j : B)
    {
        int i = 0, k = j;

        for (auto el : M)
        {
            i = 0;
            while (j > 0 && j % el.first == 0 && i < el.second)
            {
                j /= el.first;
                i++;
            }
            if (j == 0)
            {
                Ans.push_back(k);
                break;
            }
        }
    }

    cout << res << "\n";
    cout << A[100] << "\n";

    for (int e : Ans)
        cout << e << " ";
    cout << "\n";
    return 0;
}