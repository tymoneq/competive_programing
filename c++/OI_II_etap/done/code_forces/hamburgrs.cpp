#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string burger;
    long long money, res = 0, tmp_res = 0, n_bread, n_sausage, n_cheese, p_bread, p_sausage, p_cheese, needed_bread = 0, needed_sausage = 0, needed_cheese = 0, cost = 0, n_b, n_s, n_c;
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
        res = numeric_limits<int>::max();
        if (needed_bread != 0)
            res = n_bread / needed_bread;
        if (needed_sausage != 0)
            res = min(res, n_sausage / needed_sausage);
        if (needed_cheese != 0)
            res = min(res, n_cheese / needed_cheese);
        n_bread -= needed_bread * res;
        n_sausage -= needed_sausage * res;
        n_cheese -= needed_cheese * res;
    }
    if (needed_bread != 0)
        tmp_res = max(tmp_res, n_bread / needed_bread);
    if (needed_sausage != 0)
        tmp_res = max(tmp_res, n_sausage / needed_sausage);
    if (needed_cheese != 0)
        tmp_res = max(tmp_res, n_cheese / needed_cheese);
    if (tmp_res != 0)
    {
        n_b = n_bread;
        n_s = n_sausage;
        n_c = n_cheese;
        if (needed_bread != 0 && n_bread / needed_bread < tmp_res)
        {
            cost += p_bread * (tmp_res * needed_bread - n_bread);
            n_bread = tmp_res * needed_bread;
        }
        if (needed_sausage != 0 && n_sausage / needed_sausage < tmp_res)
        {
            cost += p_sausage * (tmp_res * needed_sausage - n_sausage);
            n_sausage = tmp_res * needed_sausage;
        }
        if (needed_cheese != 0 && n_cheese / needed_cheese < tmp_res)
        {
            cost += p_cheese * (tmp_res * needed_cheese - n_cheese);
            n_cheese = tmp_res * needed_cheese;
        }
        if (cost <= money)
        {
            n_bread -= needed_bread * tmp_res;
            n_sausage -= needed_sausage * tmp_res;
            n_cheese -= needed_cheese * tmp_res;
            res += tmp_res;
            money -= cost;
            tmp_res = 0;
        }
        else
        {
            cost = 0;
            if (needed_bread != 0 && n_b / needed_bread < tmp_res)
                cost += p_bread * (needed_bread - n_b);
            if (needed_sausage != 0 && n_s / needed_sausage < tmp_res)
                cost += p_sausage * (needed_sausage - n_s);
            if (needed_cheese != 0 && n_c / needed_cheese < tmp_res)
                cost += p_cheese * (needed_cheese - n_c);
            res += money / cost;
            money = 0;
        }
    }
    cost = 0;
    if (tmp_res == 0 && (n_bread != 0 || n_cheese != 0 || n_sausage != 0))
    {
        if (needed_bread != 0)
            cost += (needed_bread - n_bread) * p_bread;
        if (needed_sausage != 0)
            cost += (needed_sausage - n_sausage) * p_sausage;
        if (needed_cheese != 0)
            cost += (needed_cheese - n_cheese) * p_cheese;
        if (cost <= money)
        {
            money -= cost;
            res++;
        }
    }

    cost = needed_bread * p_bread + needed_sausage * p_sausage + needed_cheese * p_cheese;
    res += money / cost;
    cout << res;
    return 0;
}
