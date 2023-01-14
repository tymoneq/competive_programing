#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fin.open("cowdance.in"), fout.open("cowdance.out");
    int n, t;
    fin >> n >> t;
    vector<int> Cows(n);
    for (int i = 0; i < n; i++)
        fin >> Cows[i];

    int l = 1, r = n, sol = n, mid, time, j, s;
    priority_queue<int> pq;
    while (l <= r)
    {
        mid = l + (r - l + 1) / 2;
        time = 0, j = 0;
        s = 0;
        while (s < mid && j < n)
        {
            pq.push(-Cows[j]);
            s++, j++;
        }
        while (!pq.empty())
        {
            time += max(0, -pq.top() - time);
            pq.pop();
            if (j < n)
            {
                pq.push(-(Cows[j] + time));
                j++;
            }
        }
        if (time > t)
            l = mid + 1;
        else
        {
            sol = min(sol, mid);
            r = mid - 1;
        }
    }
    fout << sol;
    fin.close(), fout.close();
    return 0;
}