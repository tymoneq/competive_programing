#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> Leona(n), Zoe(m);
    for (int i = 0; i < n; i++)
        cin >> Leona[i];
    for (int i = 0; i < m; i++)
        cin >> Zoe[i];
    bool move = 1; // 0- Leona 1 - zoe
    string word = Leona[0];
    for (int i = 1; i < n + m; i++)
    {
        if (move)
        {
            bool fint = 0;
            for (string s : Zoe)
                if (word.size() <= s.size())
                {
                    bool corect = 1;
                    for (int j = 0; j < word.size(); j++)
                        if (word[j] > s[j])
                        {
                            corect = 0;
                            break;
                        }
                    if (corect)
                    {
                        fint = 1;
                        word = s;
                        break;
                        move = 0;
                    }
                }
            if (!fint)
            {
                char next = word[0] + 1;
                for (string s : Zoe)
                {
                    if (s[0] == next)
                    {
                        word = s;
                        fint = 1;
                        move = 0;
                        break;
                    }
                }
            }
            if (!fint)
                break;
        }
        else
        {
            bool fint = 0;
            for (string s : Leona)
                if (word.size() <= s.size())
                {
                    bool corect = 1;
                    for (int j = 0; j < word.size(); j++)
                        if (word[j] > s[j])
                        {
                            corect = 0;
                            break;
                        }
                    if (corect)
                    {
                        fint = 1;
                        word = s;
                        break;
                        move = 1;
                    }
                }
            if (!fint)
            {
                char next = word[0] + 1;
                for (string s : Leona)
                {
                    if (s[0] == next)
                    {
                        word = s;
                        fint = 1;
                        move = 1;
                        break;
                    }
                }
            }
            if (!fint)
                break;
        }
    }
    if (move)
        cout << "Leona";
    else
        cout << "Zoe";
    return 0;
}