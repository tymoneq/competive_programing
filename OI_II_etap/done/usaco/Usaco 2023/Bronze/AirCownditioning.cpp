#include <bits/stdc++.h>

using namespace std;
int Cows[110], TMP[110];
struct AirCowndition
{
    int p, k, power, cost;
};
vector<vector<int>> Sub(vector<int> &nums)
{
    int bits = nums.size();

    unsigned int pow_set_size = pow(2, bits);

    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<string> list;
    for (int counter = 0; counter < pow_set_size;
         counter++)
    {
        vector<int> subset;
        string temp = "";

        for (int j = 0; j < bits; j++)
        {
            if (counter & (1 << j))
            {
                subset.push_back(nums[j]);

                temp += to_string(nums[j]) + '$';
            }
        }

        if (find(list.begin(), list.end(), temp) == list.end())
        {
            ans.push_back(subset);
            list.push_back(temp);
        }
    }

    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b, c, cost = 0;
    cin >> n >> m;
    vector<AirCowndition> A(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        for (int j = a; j <= b; j++)
            Cows[j] += c;
    }
    for (int i = 0; i < m; i++)
        cin >> A[i].p >> A[i].k >> A[i].power >> A[i].cost;
    vector<int> S(m);
    for (int i = 0; i < m; i++)
        S[i] = i;
    vector<vector<int>> Subsets = Sub(S);
    int res = numeric_limits<int>::max();
    bool corect = 1;
    for (int i = 0; i < Subsets.size(); i++)
    {
        if (Subsets[i].size() == 0)
            continue;
        cost = 0;
        for (int j = 0; j < 105; j++)
            TMP[j] = Cows[j];
        for (int w : Subsets[i])
        {
            cost += A[w].cost;
            for (int j = A[w].p; j <= A[w].k; j++)
                TMP[j] -= A[w].power;
        }
        corect = 1;
        for (int j = 0; j <= 105; j++)
            if (TMP[j] > 0)
            {
                corect = 0;
                break;
            }
        if (corect)
            res = min(res, cost);
    }
    cout << res;
    return 0;
}