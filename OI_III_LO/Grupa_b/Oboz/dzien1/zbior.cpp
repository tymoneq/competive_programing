#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, a;
    set<int> S;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        S.insert(a);
    }
    cin >> k;
    bool corect;
    vector<int> Q;
    for (int K = 0; K < k; K++)
    {
        cin >> a;
        if (a == 0)
            cout << "TAK\n";
        else
        {
            Q.push_back(a);
            corect = 0;
            for (auto A : Q)
            {
                Q.pop_back();
                if (corect)
                    break;
                for (auto w : S)
                {
                    if (A % w == 0)
                    {
                        corect = 1;
                        break;
                    }
                    else if (w > A)
                        break;
                    else
                        Q.push_back(A - w);
                }
            }
            Q.clear();
            cout << (corect ? "TAK\n" : "NIE\n");
        }
    }
    return 0;
}