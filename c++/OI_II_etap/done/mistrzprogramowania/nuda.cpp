#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> k >> n;
    int N = n;
    for (int i = 0; i < k; i++)
        cout << "$ ";
    cout << "\n";
    N -= k;
    int prev = k + 2;
    while (N > 0)
    {
        if (N < prev)
            for (int i = 0; i < N; i++)
                cout << "$ ";
        else
            for (int i = 0; i < prev; i++)
                cout << "$ ";
        cout << "\n";
        N -= prev;
        prev += 2;
    }

    return 0;
}