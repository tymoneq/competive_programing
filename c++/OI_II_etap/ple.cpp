#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
struct item
{
    int weight;
    int index;
};
inline bool sorto(item const &lhs, item const &rhs)
{
    if (lhs.weight < rhs.weight)
        return true;
    if (lhs.weight == rhs.weight && lhs.index < rhs.index)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a;
    cin >> n;
    vector<item> Weight(n);
    item it;
    vector<ull> res;
    vector<ull> Stan(n, 0);
    ull sum = 0;
    int min_index = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> it.weight;
        it.index = i;
        Weight[i] = it;
    }
    sort(Weight.begin(), Weight.end(), sorto);
    res.push_back(Weight[0].weight);
    sum = Weight[0].weight;
    for (int i = Weight[0].index; i < n; i++)
        Stan[i] = Weight[0].weight;

    Weight.erase(Weight.begin());
    ull last_el = 0;
    vector<item>::iterator iter;
    for (int i = 1; i < n; i++)
    {
        iter = Weight.begin();
        it = Weight[0];
        sum += it.weight;
        last_el = it.weight;
        for (int j = 1; j < Weight.size() - 1; j++)
        {
            if (Weight[j].index < it.index && Weight[j].weight + Stan[Weight[j].index] <= sum)
            {
                sum -= last_el;
                sum += Weight[j].weight;
                last_el = Weight[j].weight;
                iter++;
            }
            if (Weight[j].index == min_index)
            {
                min_index++;
                break;
            }
        }
        for (int j = (*iter).index; j < n; j++)
            Stan[j] += (*iter).weight;
        res.push_back(sum);
        Weight.erase(iter);
    }
    for (ull el : res)
        cout << el << " ";
    return 0;
}