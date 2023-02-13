#include <bits/stdc++.h>
using namespace std;
struct gracz
{
    string name;
    int Rounds;
    int MAX;
    int points;
    vector<int> Points;
};
inline bool sortPlayers(gracz &lhs, gracz &rhs)
{
    if (lhs.Rounds > rhs.Rounds)
        return 1;
    if (lhs.Rounds == rhs.Rounds && lhs.MAX > rhs.MAX)
        return 1;
    if (lhs.Rounds == rhs.Rounds && lhs.MAX == rhs.MAX && lhs.points > rhs.points)
        return 1;
    if (lhs.Rounds == rhs.Rounds && lhs.MAX == rhs.MAX && lhs.points == rhs.points && lhs.name < rhs.name)
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a;
    cin >> n;
    vector<gracz> V(n);
    for (int i = 0; i < n; i++)
    {
        cin >> V[i].name;
        for (int j = 0; j < 5; j++)
        {
            cin >> a;
            if (a != 0)
                V[i].Rounds++;
            V[i].points += a;
            V[i].Points.push_back(a);
            if (a == 500)
                V[i].MAX++;
        }
    }
    sort(V.begin(), V.end(), sortPlayers);
    int place = 1, newplace = 0;
    for (int i = 0; i < n; i++)
    {
        cout << place << " " << V[i].name << " " << V[i].points << " ";
        for (int w : V[i].Points)
            cout << w << " ";
        cout << "\n";
        if (i + 1 < n && V[i + 1].points == V[i].points && V[i + 1].MAX == V[i].MAX && V[i].Rounds == V[i + 1].Rounds)
            newplace++;
        else
        {
            place++;
            place += newplace;
            newplace = 0;
        }
    }

    return 0;
}