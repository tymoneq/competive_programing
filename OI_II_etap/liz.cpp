#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6 + 10;
pair<int, int> Ans[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, sum = 0, l, r;
    string lizak;
    cin >> n >> m >> lizak;
    vector<int> Waniliowe;
    vector<pair<int, int>> Zapytania(m);
    for (int i = 0; i < m; i++)
    {
        cin >> Zapytania[i].first;
        Zapytania[i].second = i;
    }

    sort(Zapytania.begin(), Zapytania.end(), greater<pair<int, int>>());

    for (int i = 0; i < n; i++)
    {
        sum += (lizak[i] == 'T' ? 2 : 1);
        if (lizak[i] == 'W')
            Waniliowe.push_back(i);
    }
    l = 0, r = n - 1;
    for (auto q : Zapytania)
    {
        if (q.first > sum)
            Ans[q.second].first = -1;
        else if (q.first == sum)
            Ans[q.second] = {l + 1, r + 1};

        else
        {
            if (sum - (lizak[l] == 'T' ? 2 : 1) - (lizak[r] == 'T' ? 2 : 1) >= q.first)
            {
                if (sum - (lizak[l] == 'T' ? 2 : 1) == q.first)
                    Ans[q.second] = {l + 2, r + 1};
                else if (sum - (lizak[r] == 'T' ? 2 : 1) == q.first)
                    Ans[q.second] = {l + 1, r};
                else if (sum - (lizak[l] == 'T' ? 2 : 1) - (lizak[r] == 'T' ? 2 : 1) == q.first)
                    Ans[q.second] = {l + 2, r};
            }
            else if (sum - (lizak[l] == 'T' ? 2 : 1) - (lizak[r] == 'T' ? 2 : 1) < q.first)
                Ans[q.second].first = -1;
            else
            {
                while (!(sum - (lizak[l] == 'T' ? 2 : 1) - (lizak[r] == 'T' ? 2 : 1) >= q.first) && sum >= q.first)
                {
                    if (lizak[l] == lizak[r])
                    {
                        auto itL = upper_bound(Waniliowe.begin(), Waniliowe.end(), l);
                        auto itR = upper_bound(Waniliowe.begin(), Waniliowe.end(), r);
                        if (itR == Waniliowe.begin() || Waniliowe.size() == 0)
                        {
                            sum -= (lizak[r] == 'T' ? 2 : 1);
                            r--;
                            continue;
                        }
                        if (itL == Waniliowe.end())
                        {
                            sum -= (lizak[l] == 'T' ? 2 : 1);
                            l++;
                            continue;
                        }
                        itR--;
                        if (*itL - l > r - *itR)
                        {
                            sum -= (lizak[r] == 'T' ? 2 : 1);
                            r--;
                        }
                        else
                        {
                            sum -= (lizak[l] == 'T' ? 2 : 1);
                            l++;
                        }
                    }
                    else
                    {
                        sum -= 2;
                        if (lizak[l] == 'W')
                            r--;
                        else
                            l++;
                    }
                }

                if (sum - (lizak[l] == 'T' ? 2 : 1) == q.first)
                    Ans[q.second] = {l + 2, r + 1};
                else if (sum - (lizak[r] == 'T' ? 2 : 1) == q.first)
                    Ans[q.second] = {l + 1, r};
                else if (sum - (lizak[l] == 'T' ? 2 : 1) - (lizak[r] == 'T' ? 2 : 1) == q.first)
                    Ans[q.second] = {l + 2, r};

                else
                    Ans[q.second].first = -1;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (Ans[i].first == -1)
            cout << "NIE\n";
        else
            cout << Ans[i].first << " " << Ans[i].second << "\n";
    }
    return 0;
}