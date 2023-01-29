#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    int n, c;
    fin.open("helpcross.in"), fout.open("helpcross.out");
    fin >> c >> n;
    vector<int> Chickens(c);
    for (int i = 0; i < c; i++)
        fin >> Chickens[i];
    sort(Chickens.begin(), Chickens.end());
    vector<pair<int, int>> Cows(n);
    for (int i = 0; i < n; i++)
        fin >> Cows[i].first >> Cows[i].second;

    sort(Cows.begin(), Cows.end());
    int res = 0, cow_at = 0;
    priority_queue<int> availalbe_cows;
    for (int el : Chickens)
    {
        while (cow_at < n && Cows[cow_at].first <= el)
        {
            availalbe_cows.push(-Cows[cow_at].second);
            cow_at++;
        }
        while (!availalbe_cows.empty() && -availalbe_cows.top() < el)
            availalbe_cows.pop();
        if (!availalbe_cows.empty())
        {
            res++;
            availalbe_cows.pop();
        }
    }
    fout << res;
    fin.close(), fout.close();
    return 0;
}