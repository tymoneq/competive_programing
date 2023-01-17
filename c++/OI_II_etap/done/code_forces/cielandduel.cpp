#include <bits/stdc++.h>

using namespace std;
struct Card
{
    bool type;
    int strenght;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a;
    string s;
    cin >> n >> m;
    vector<Card> jiro(n);
    vector<Card> Ciel(m);
    for (int i = 0; i < n; i++)
    {
        cin >> s >> a;
        jiro[i] = {s == "ATK", a};
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        Ciel[i] = {1, a};
    }

    sort(jiro.begin(), jiro.end(), [](const Card &a, const Card &b)
         {
        if(a.type == b.type)
            return a.strenght < b.strenght;
        return a.type > b.type; });

    sort(Ciel.begin(), Ciel.end(), [](const Card &a, const Card &b)
         { return a.strenght > b.strenght; });
    int appr1 = 0;
    for (int i = 0; i < min(n, m); i++)
    {
        if (!jiro[i].type || Ciel[i].strenght <= jiro[i].strenght)
            break;
        appr1 += Ciel[i].strenght - jiro[i].strenght;
    }
    reverse(jiro.begin(), jiro.end()), reverse(Ciel.begin(), Ciel.end());
    vector<bool> done(m);
    int appr2 = 0;
    for (int i = 0; i < n; i++)
    {
        bool fnd = 0;
        for (int j = 0; j < m; j++)
        {
            if (!done[j] && ((jiro[i].type && Ciel[j].strenght >= jiro[i].strenght) || (!jiro[i].type && Ciel[j].strenght > jiro[i].strenght)))
            {
                done[j] = 1;
                if (jiro[i].type)
                    appr2 += Ciel[j].strenght - jiro[i].strenght;
                fnd = 1;
                break;
            }
        }
        if (!fnd)
        {
            cout << appr1;
            return 0;
        }
    }

    for (int i = 0; i < m; i++)
        if (!done[i])
            appr2 += Ciel[i].strenght;

    cout << max(appr1, appr2);
    return 0;
}