#include <bits/stdc++.h>
using namespace std;
const int m = 37, MOD = 1e9 + 9;
vector<vector<long long>> Cows(30);
vector<long long> All_characteristic;
int n;
inline bool check(long long A, long long B)
{
    bool aNotB = 0, Bnota = 0, both = 0;
    for (int i = 0; i < n; i++)
    {
        bool HasA = 0, hasB = 0;
        for (int j = 0; j < Cows[i].size(); j++)
        {
            if (Cows[i][j] == A)
                HasA = 1;
            if (Cows[i][j] == B)
                hasB = 1;
        }

        if (HasA && !hasB)
            aNotB = 1;
        if (!HasA && hasB)
            Bnota = 1;
        if (hasB && HasA)
            both = 1;
    }
    if (aNotB && Bnota && both)
        return 0;
    else
        return 1;
}
int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fin.open("evolution.in"), fout.open("evolution.out");
    int k;
    string s;
    fin >> n;
    long long val = 0;

    for (int i = 0; i < n; i++)
    {
        fin >> k;
        for (int j = 0; j < k; j++)
        {
            fin >> s;
            val = 0;
            for (int h = 0; h < s.size(); h++)
                val = (val * m + (s[h] - 'a' + 1)) % MOD;
            Cows[i].push_back(val);
            if (find(All_characteristic.begin(), All_characteristic.end(), val) == All_characteristic.end())
                All_characteristic.push_back(val);
        }
    }
    for (int i = 0; i < (int)All_characteristic.size(); i++)
    {
        for (int j = i + 1; j < (int)All_characteristic.size(); j++)
        {
            if (!check(All_characteristic[i], All_characteristic[j]))
            {
                fout << "no";
                fin.close(), fout.close();
                return 0;
            }
        }
    }
    fout << "yes";
    fin.close(), fout.close();
    return 0;
}