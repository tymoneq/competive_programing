#include <bits/stdc++.h>

using namespace std;
vector<int> Nums;
string s;
int ind, b;
int calcRes()
{
    int l, r;
    if (s[b] == '?')
    {
        ind++;
        b += 2;
        return Nums[ind];
    }
    else if (s[b] == 'm' && s[b + 2] == 'n')
    {
        b += 4;
        l = calcRes();
        r = calcRes();
        b++;
        return min(l, r);
    }
    else if (s[b] == 'm' && s[b + 2] == 'x')
    {
        b += 4;
        l = calcRes();
        r = calcRes();
        b++;
        return max(l, r);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    int counter = 0;
    for (char z : s)
        if (z == '?')
            counter++;
    Nums.resize(counter);
    for (int i = 0; i < counter; i++)
        Nums[i] = i + 1;
    set<int> Res;
    int tmp;
    while (next_permutation(Nums.begin(), Nums.end()))
    {
        ind = -1;
        tmp = calcRes();
        Res.insert(tmp);
        b = 0;
    }

    cout << Res.size();
    return 0;
}