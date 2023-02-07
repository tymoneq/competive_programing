#include <bits/stdc++.h>

using namespace std;
constexpr int M = 1e5+10;
int Num[M], Val[M], Path[M], Ind[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    set<int> Res;
    for (int i = 0; i < n; i++)
    {
        cin >> Num[i];
        Ind[Num[i]] = i;
    }
    priority_queue<pair<int, int>> pq;
    set<int> Nums;
    queue<pair<int, int>> q;
    for (int i = n - 1; i >= 0; i--)
    {
        if (Nums.upper_bound(Num[i]) == Nums.end())
        {
            Path[i] = i;
            Val[i] = 1;
            pq.push({1, Num[i]});
            Nums.insert(Num[i]);
        }
        else
        {
            while (pq.top().second < Num[i])
            {
                q.push(pq.top());
                pq.pop();
            }
            Val[i] = pq.top().first + 1;
            Path[i] = Ind[pq.top().second];
            pq.push({Val[i], Num[i]});
            while (!q.empty())
            {
                pq.push(q.front());
                q.pop();
            }
            Nums.insert(Num[i]);
        }
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
        mx = max(mx, Val[i]);

    int jmp = 0;
    for (int i = 0; i < n; i++)
        if (Val[i] == mx)
        {
            Res.insert(Num[i]);
            jmp = Path[i];
            while (jmp != Path[jmp])
            {
                Res.insert(Num[jmp]);
                jmp = Path[jmp];
            }
            Res.insert(Num[jmp]);
        }

    cout << Res.size() << "\n";
    for (int w : Res)
        cout << w << " ";
    return 0;
}