#include <bits/stdc++.h>
using namespace std;
constexpr int M = 2e5 + 10;
int Arr[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    multiset<int> lo, hi;
    for (int i = 0; i < k; i++)
    {
        cin >> Arr[i];
        lo.insert(Arr[i]);
    }
    if (k % 2 == 0)
    {
        while (lo.size() != hi.size())
        {
            auto it = lo.end();
            it--;
            hi.insert(*it);
            lo.erase(it);
        }
    }
    if (k % 2 == 1)
    {
        while (lo.size() - 1 != hi.size())
        {
            auto it = lo.end();
            it--;
            hi.insert(*it);
            lo.erase(it);
        }
    }
    auto it = lo.end();
    it--;
    cout << *it << " ";
    int ind = 0;
    for (int i = k; i < n; i++)
    {
        cin >> Arr[i];
        auto itr = find(lo.begin(), lo.end(), Arr[ind]);
        if (itr != lo.end())
            lo.erase(itr);
        else
        {
            itr = find(hi.begin(), hi.end(), Arr[ind]);
            hi.erase(itr);
        }
        ind++;
        if (*hi.begin() < Arr[i])
            hi.insert(Arr[i]);
        else
            lo.insert(Arr[i]);
        if (k % 2 == 0)
        {
            if (lo.size() > 0)
            {
                it = lo.end();
                it--;
                while (*it > *hi.begin() && lo.size() > 0)
                {
                    hi.insert(*it);
                    lo.erase(it);
                    if (lo.size() > 0)
                    {
                        it = lo.end();
                        it--;
                    }
                }
            }
            if (hi.size() > lo.size())
                while (lo.size() != hi.size())
                {
                    it = hi.begin();
                    lo.insert(*it);
                    hi.erase(it);
                }
            else
                while (lo.size() != hi.size())
                {
                    it = lo.end();
                    it--;
                    hi.insert(*it);
                    lo.erase(it);
                }
        }
        else if (k % 2 == 1)
        {
            if (lo.size() > 0)
            {
                it = lo.end();
                it--;
                while (*it > *hi.begin() && lo.size() > 0)
                {
                    hi.insert(*it);
                    lo.erase(it);
                    if (lo.size() > 0)
                    {
                        it = lo.end();
                        it--;
                    }
                }
            }
            if (hi.size() > lo.size())
                while (lo.size() - 1 != hi.size())
                {
                    it = hi.begin();
                    lo.insert(*it);
                    hi.erase(it);
                }
            else
                while (lo.size() - 1 != hi.size())
                {
                    it = lo.end();
                    it--;
                    hi.insert(*it);
                    lo.erase(it);
                }
        }
        it = lo.end();
        it--;
        cout << *it << " ";
    }
    return 0;
}