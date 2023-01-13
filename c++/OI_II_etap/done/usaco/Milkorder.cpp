#include <bits/stdc++.h>

using namespace std;
bool inSocialStatus[105];
int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fin.open("milkorder.in"), fout.open("milkorder.out");
    int n, k, m, x, v, index = 0;
    fin >> n >> m >> k;
    vector<int> Social_status(m);
    vector<int> Data_social_status;
    vector<pair<int, int>> Poz(k);
    vector<int> Cows(n + 1);
    for (int i = 0; i < m; i++)
    {
        fin >> Social_status[m - i - 1];
        inSocialStatus[Social_status[m - i - 1]] = 1;
    }
    for (int i = 0; i < k; i++)
        fin >> Poz[i].second >> Poz[i].first;
    Data_social_status = Social_status;
    sort(Poz.begin(), Poz.end());
    for (int i = 0; i < k; i++)
    {
        x = Poz[i].second;
        Cows[Poz[i].first] = x;
        if (inSocialStatus[x])
        {
            for (int j = Social_status.size() - 1; j >= 0; j--)
                if (Social_status[j] == x)
                {
                    index = j;
                    break;
                }
            inSocialStatus[index] = 0;
            for (int j = index + 1; j < Social_status.size(); j++)
            {
                inSocialStatus[j] = 0;
                for (int h = Poz[i].first; h > 0; h--)
                    if (Cows[h] == 0)
                    {
                        Cows[h] = Social_status[j];
                        break;
                    }
            }
            for (int j = Social_status.size() - 1; j >= index; j--)
            {
                auto it = Social_status.end();
                it--;
                Social_status.erase(it);
            }
        }
    }
    bool fint = 0;
    for (int i = 0; i < Social_status.size(); i++)
        if (Social_status[i] == 1)
        {
            fint = 1;
            break;
        }
    int prev_val = 0;
    if (fint)
        for (int i = Social_status.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < m; j++)
                if (Data_social_status[j] == Social_status[i])
                {
                    if (j + 1 < m)
                        prev_val = Data_social_status[j + 1];
                    else
                        prev_val = 0;
                    break;
                }
            bool fint_prev = 0;
            for (int j = 1; j <= n; j++)
            {
                if (Cows[j] == prev_val)
                    fint_prev = 1;
                if (Cows[j] == 0 && fint_prev)
                {
                    Cows[j] = Social_status[i];
                    break;
                }
            }
        }
    for (int i = 1; i <= n; i++)
        if (Cows[i] == 1)
        {
            fout << i;
            fin.close(), fout.close();
            return 0;
        }
    for (int i = 1; i <= n; i++)
        if (Cows[i] == 0)
        {
            fout << i;
            fin.close(), fout.close();
            return 0;
        }
}