#include <bits/stdc++.h>
using namespace std;
const int M = 1010, mod = 1e9 + 9, p = 37;
int Res[M];
long long LOG[M][3];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, new_points = 0, mx = numeric_limits<int>::min(), mx_index = numeric_limits<int>::max(), j;
    long long tmp;
    vector<long long> V;
    vector<int> r;
    vector<string> Wordss;
    string word;
    bool foundd = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> word >> new_points;
        tmp = word[0] - 'a' + 1;
        foundd = 0;
        for (j = 1; j < word.size(); j++)
            tmp = (tmp * p + (word[j] - 'a' + 1)) % mod;
        for (j = 0; j < V.size(); j++)
            if (V[j] == tmp)
            {
                foundd = 1;
                Res[j] += new_points;
                if (new_points < 0)
                {
                    mx = numeric_limits<int>::min();
                    for (int k = 0; k < V.size(); k++)
                        if (Res[k] > mx)
                            mx = Res[k];
                }
                break;
            }

        if (!foundd)
        {
            V.push_back(tmp);
            Res[V.size() - 1] = new_points;
            Wordss.push_back(word);
        }
        mx = max(mx, Res[j]);
        LOG[i][0] = tmp, LOG[i][1] = Res[j];
    }
    for (int i = 0; i < V.size(); i++)
        if (Res[i] == mx)
            r.push_back(i);
    for (int i = 0; i < r.size(); i++)
        for (int k = 0; k < n; k++)
            if (LOG[k][0] == V[r[i]] && LOG[k][1] >= mx)
            {
                mx_index = min(mx_index, k);
                break;
            }

    for (int i = 0; i < V.size(); i++)
        if (V[i] == LOG[mx_index][0])
        {
            cout << Wordss[i];
            break;
        }
    return 0;
}