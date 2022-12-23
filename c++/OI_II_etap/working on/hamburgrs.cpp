#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string burger;
    long long money, res = numeric_limits<int>::max(), tmp_res = 0;
    int n_bread, n_sausage, n_cheese, p_bread, p_sausage, p_cheese, needed_bread = 0, needed_sausage = 0, needed_cheese = 0, cost = 0;
    cin >> burger >> n_bread >> n_sausage >> n_cheese >> p_bread >> p_sausage >> p_cheese >> money;
    for (int i = 0; i < burger.size(); i++)
    {
        if (burger[i] == 'B')
            needed_bread++;
        else if (burger[i] == 'S')
            needed_sausage++;
        else
            needed_cheese++;
    }
    if (needed_bread <= n_bread && needed_sausage <= n_sausage && needed_cheese <= n_cheese)
    {
        tmp_res = needed_bread / n_bread;
        if (tmp_res == 0)
            tmp_res = needed_bread;
        res = min(res, tmp_res);
        tmp_res = needed_sausage / n_sausage;
        if (tmp_res == 0)
            tmp_res = needed_sausage;
        res = min(res, tmp_res);
        tmp_res = needed_cheese / n_cheese;
        if (tmp_res == 0)
            tmp_res = needed_cheese;
        res = min(res, tmp_res);
        n_bread -= needed_bread * res;
        n_sausage -= needed_sausage * res;
        n_cheese -= needed_cheese * res;
    }
    if (res == numeric_limits<int>::max())
        res = 0;
    if ((needed_bread - n_bread) * p_bread <= money)
    {
        if (needed_bread != 0 && n_bread < needed_bread)
            money -= (needed_bread - n_bread) * p_bread;
        if ((needed_sausage - n_sausage) * p_sausage <= money)
        {
            if (needed_sausage != 0 && n_sausage < needed_sausage)
                money -= (needed_sausage - n_sausage) * p_sausage;
            if ((needed_cheese - n_cheese) * p_cheese <= money)
            {
                res++;
                if (needed_cheese != 0 && n_cheese < needed_cheese)
                    money -= (needed_cheese - n_cheese) * p_cheese;
            }
        }
    }
    if (n_bread >= needed_bread)
    {
        cost = needed_sausage * p_sausage + needed_cheese * p_cheese;
        if (money / cost >= n_bread / needed_bread)
        {
            res += n_bread / needed_bread;
            money -= cost * (n_bread / needed_bread);
        }
    }
    if (n_sausage >= needed_sausage)
    {
        cost = needed_bread * p_bread + needed_cheese * p_cheese;
        if (money / cost >= n_sausage / needed_sausage)
        {
            res += n_sausage / needed_sausage;
            money -= cost * (n_sausage / needed_sausage);
        }
    }
    if (n_cheese >= needed_cheese)
    {
        cost = needed_sausage * p_sausage + needed_bread * p_bread;
        if (money / cost >= n_cheese / needed_cheese)
        {
            res += n_cheese / needed_cheese;
            money -= cost * (n_cheese / needed_cheese);
        }
    }
    cost = needed_bread * p_bread + needed_sausage * p_sausage + needed_cheese * p_cheese;
    res += money / cost;
    cout << res;
    return 0;
}
