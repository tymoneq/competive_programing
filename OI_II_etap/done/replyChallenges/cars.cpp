#include <bits/stdc++.h>
using namespace std;
struct cars
{
    int id;
    int normalSpeed, turboSpeed, cooldown, durationtime;
    int blocktime, blockdistance;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, c, R;
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        cin >> R >> c;
        vector<cars> Cars(c);
        pair<double, int> mintime;
        mintime.first = numeric_limits<int>::max();
        mintime.second = 1000;
        for (int i = 0; i < c; i++)
        {
            cin >> Cars[i].id >> Cars[i].normalSpeed >> Cars[i].turboSpeed >> Cars[i].cooldown >> Cars[i].durationtime;
            Cars[i].blockdistance = Cars[i].normalSpeed * Cars[i].cooldown + Cars[i].turboSpeed * Cars[i].durationtime;
            Cars[i].blocktime = Cars[i].cooldown + Cars[i].durationtime;
        }
        for (int i = 0; i < c; i++)
        {
            double time = (R / Cars[i].blockdistance) * Cars[i].blocktime;
            if (R % Cars[i].blockdistance != 0)
            {
                int d = R % Cars[i].blockdistance;
                double add = 0;
                if (d <= (Cars[i].turboSpeed * Cars[i].durationtime))
                    add = d / Cars[i].turboSpeed;
                else
                {
                    add = Cars[i].durationtime;
                    d -= Cars[i].turboSpeed * Cars[i].durationtime;
                    add += d / Cars[i].normalSpeed;
                }
                time += add;
            }
            if (time < mintime.first)
            {
                mintime.second = i;
                mintime.first = time;
            }
            if (time <= mintime.first)
            {
                mintime.second = min(i, mintime.second);
                mintime.first = time;
            }
        }
        cout << "Case #" << T << ": " << mintime.second << "\n";
    }
    return 0;
}