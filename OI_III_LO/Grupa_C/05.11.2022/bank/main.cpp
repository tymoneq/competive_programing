#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double w, k;
    cin >> w >> k;
    vector<pair<int, int>> Res;
    vector<double> numbers(100);
    for (double i = 0; i < 100; i++)
        numbers[i] = i;
    for (double y = 1; y < 100; y++)
    {
        double x = (y * (k - 100) - (w * 100)) / (1 - 100 * k);
        auto itr = binary_search(numbers.begin(), numbers.end(), x);
        if (itr)
            Res.push_back(make_pair(x, y));
    }
    if (Res.size() == 0)
    {
        cout << "brak";
        return 0;
    }
    for (auto el : Res)
        cout << el.first << " " << el.second << " ";
    return 0;
}