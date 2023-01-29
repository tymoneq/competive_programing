#include <bits/stdc++.h>
// Tymon Tumialis
using namespace std;

struct track
{
    double poz_start = 0;
    double dl = 0;
    double v = 0;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, wyprzedone = 1;
    double V_auto, W, M, D;
    cin >> n >> D >> W >> M;
    pair<double, int> V_mal; // first = V second = index
    vector<track> poz(n + 1);
    vector<int> track_length(n + 1, 0);
    V_auto = W / M;
    for (int i = 1; i <= n; i++)
    {
        double x, d, w, m;
        cin >> x >> d >> w >> m;
        double v = w / m;
        track l;
        l.poz_start = x;
        l.dl = d;
        l.v = v;
        poz[i] = l;
        track_length[i] = track_length[i - 1] + d;
    }
    // znalezienie pierwszej mniejszej prędkości od tyłu
    int index = 1;
    for (int i = n; i >= 2; i--)
    {
        if (poz[i].v < poz[i - 1].v)
        {
            index = i;
            V_mal = make_pair(poz[i].v, i);
            break;
        }
    }
    vector<double> Time_to_connect(index + 1, 0);
    double time = 0;
    Time_to_connect[index] = -1;
    for (int i = index - 1; i >= 1; i--) // i==3 dal testu 182 działa źle sprawdź
    {
        if (poz[i].v <= V_mal.first)
        {
            if (poz[i].poz_start == poz[i + 1].poz_start - poz[i + 1].dl && poz[i].v == poz[i + 1].v)
                Time_to_connect[i] = 0;
            else
                Time_to_connect[i] = -1;
            if (poz[i].v < V_mal.first)
            {
                V_mal.first = poz[i].v;
                V_mal.second = i;
            }
        }
        else
        {
            double fix_time = 0;
            double timer = 0;
            double droga_1 = poz[i].poz_start;
            double kon_2 = poz[i + 1].poz_start - poz[i + 1].dl;
            for (int j = i + 1; j <= V_mal.second; j++)
            {
                if (droga_1 == kon_2 && poz[i].v >= poz[i + 1].v)
                {
                    Time_to_connect[i] = timer;
                    break;
                }
                if (droga_1 > kon_2)
                {
                    double fix_poz = droga_1 - kon_2;
                    fix_time = fix_poz / poz[i].v;
                    Time_to_connect[i] = timer - fix_time;
                    break;
                }
                if (poz[j].v < poz[i].v)
                {
                    /* Calculating the time it takes for the track to catch up to the track in front of it. */
                    time = (poz[j].poz_start - track_length[j] + track_length[i] - poz[i].poz_start) / (poz[i].v - poz[j].v);
                    if (Time_to_connect[j] == -1)
                    {
                        fix_time = (kon_2 - droga_1) / (poz[i].v - poz[j].v);
                        Time_to_connect[i] = fix_time + timer;
                        break;
                    }
                    else if (time < Time_to_connect[j])
                    {
                        fix_time = (kon_2 - droga_1) / (poz[i].v - poz[j].v);
                        Time_to_connect[i] = fix_time + timer;
                        break;
                    }
                    else if (Time_to_connect[j] > timer)
                    {
                        timer = Time_to_connect[j] - timer;
                        droga_1 += poz[i].v * timer;
                        kon_2 += poz[j].v * timer;
                        timer = Time_to_connect[j];
                    }
                }
                else if (Time_to_connect[j] > timer)
                {
                    timer = Time_to_connect[j] - timer;
                    droga_1 += poz[i].v * timer;
                    kon_2 += poz[j].v * timer; // sprawdź czy większa prędkość jest tu
                    timer = Time_to_connect[j];
                }
            }
        }
    }

    // gdy V_1> V_2
    for (int i = 1; i < index; i++)
    {
        time = (poz[i].poz_start + D) / (V_auto - poz[i].v);
        double pocz_pierwszej = poz[i].poz_start + poz[i].v * time;
        double kon_drugiej = poz[i + 1].poz_start - poz[i + 1].dl + poz[i + 1].v * time;
        if (kon_drugiej - pocz_pierwszej >= D)
        {
            double distans = poz[i + 1].poz_start - poz[i + 1].dl;
            double timer = 0;
            for (int j = i + 1; j <= index; j++)
            {
                if (Time_to_connect[j] == -1)
                {
                    distans += poz[j].v * (time - timer);
                    break;
                }
                else if (timer < Time_to_connect[j])
                {
                    if (Time_to_connect[j] < time)
                    {
                        distans += poz[j].v * (Time_to_connect[j] - timer);
                        timer = Time_to_connect[j];
                    }
                    else
                    {
                        distans += poz[j].v * (time - timer);
                        break;
                    }
                }
            }
            if (distans - pocz_pierwszej >= D)
                wyprzedone += 1;
        }
    }

    // gdy V_1 <= V_2
    for (int i = index; i < n; i++)
    {
        time = (poz[i].poz_start + D) / (V_auto - poz[i].v);
        double pocz_pierwszej = poz[i].poz_start + poz[i].v * time;
        double kon_drugiej = poz[i + 1].poz_start - poz[i + 1].dl + poz[i + 1].v * time;
        if (kon_drugiej - pocz_pierwszej >= D)
            wyprzedone += 1;
    }
    cout << wyprzedone;
    return 0;
}