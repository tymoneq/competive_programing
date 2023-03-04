#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    string s;
    cin >> n >> m;
    map<char, vector<string>> Leona, Zoe;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        Leona[s[0]].push_back(s);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        Zoe[s[0]].push_back(s);
    }
    bool move = 1; // 0- leona 1 - Zoe
    string word = Leona.begin()->second[0];
    for (int i = 1; i < n + m + 10; i++)
    {
        if (move)
        {
            auto it = upper_bound(Zoe[word[0]].begin(), Zoe[word[0]].end(), word);
            if (it != Zoe[word[0]].end())
            {
                move = 0;
                word = *it;
            }
            else if (it == Zoe[word[0]].end())
            {
                if (Zoe.find(word[0] + 1) != Zoe.end())
                {
                    word = Zoe[word[0] + 1][0];
                    move = 0;
                }
                else
                {
                    cout << "Leona";
                    return 0;
                }
            }
        }
        else
        {
            auto it = upper_bound(Leona[word[0]].begin(), Leona[word[0]].end(), word);
            if (it != Leona[word[0]].end())
            {
                move = 1;
                word = *it;
            }
            else if (it == Leona[word[0]].end())
            {
                if (Leona.find(word[0] + 1) != Leona.end())
                {
                    word = Leona[word[0] + 1][0];
                    move = 1;
                }
                else
                {
                    cout << "Zoe";
                    return 0;
                }
            }
        }
    }
    return 0;
}