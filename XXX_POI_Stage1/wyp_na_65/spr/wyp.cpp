#include <bits/stdc++.h>

using namespace std;

struct track
{
    double poz_start = 0;
    double dl = 0;
    double v = 0;
};
inline bool sorto(double &lhs, double &rhs) { return lhs > rhs; }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, wyprzedone = 1;
    double V_auto, W, M, D;
    cin >> n >> D >> W >> M;
    pair<double, int> V_mal; // first = V second = index
    vector<track> poz(n + 1);
    vector<double> Sorted_V(n);
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
        Sorted_V[i - 1] = v;
        track_length[i] = track_length[i - 1] + d;
    }
    // znalezienie pierwszej mniejszej prędkości od tyłu
    sort(Sorted_V.begin(), Sorted_V.end(), sorto);
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
    vector<bool> Distance_b_tracks(index, 0); // 0 trzeba sprawdzić 1 nie trzeba
    vector<double> Time_to_connect(index + 1, 0);
    bool must_check = false;
    if (index != 1)
    {
        for (int i = 1; i < index; i++)
        {
            if (poz[i].v < poz[i + 1].v)
                must_check = true;
            else if (poz[i].v == poz[i + 1].v)
            {
                float distance_b = poz[i + 1].poz_start - poz[i + 1].dl - poz[i].poz_start;
                if (distance_b < D)
                    Distance_b_tracks[i] = true;
                else
                    must_check = true;
            }
            else if (poz[i].v > poz[i + 1].v)
            {
                float distance_b = poz[i + 1].poz_start - poz[i + 1].dl - poz[i].poz_start;
                if (distance_b <= D)
                    Distance_b_tracks[i] = true;
                else
                    must_check = true;
            }
        }
        double time = 0;
        for (int i = index - 1; i >= 1; i--)
        {
            if (poz[i].v <= V_mal.first)
            {
                Time_to_connect[i] = 0;
                if (poz[i].v < V_mal.first)
                {
                    V_mal.first = poz[i].v;
                    V_mal.second = i;
                }
            }
            // sprawdz liczenie czasu
            else
            {
                if (poz[i].v > poz[i + 1].v)
                {
                    double time = (poz[i + 1].poz_start - poz[i + 1].dl - poz[i].poz_start) / (poz[i].v - poz[i + 1].v);
                    Time_to_connect[i] = time;
                }
                else
                {
                    for (int j = i + 1; j <= V_mal.second; j++)
                    {
                        if (poz[j].v < poz[i].v)
                        {
                            double time = (poz[j].poz_start - track_length[j] + track_length[i] - poz[i].poz_start) / (poz[i].v - poz[j].v);
                            Time_to_connect[i] = time;
                            break;
                        }
                    }
                }
            }
        }
    }
    if (must_check)
    {
        // gdy V_1> V_2
        for (int i = 1; i < index; i++)
        {
            if (Distance_b_tracks[i] == 1)
                continue;
            double time = (poz[i].poz_start + D) / (V_auto - poz[i].v);
            if (time >= Time_to_connect[i] && Time_to_connect[i] != 0)
                continue;
            else
            {
                double pocz_pierwszej = poz[i].poz_start + poz[i].v * time;
                double kon_drugiej = poz[i + 1].poz_start - poz[i + 1].dl + poz[i + 1].v * time;
                if (kon_drugiej - pocz_pierwszej >= D)
                {
                    double V = (D - poz[i + 1].poz_start + poz[i + 1].dl + pocz_pierwszej) / time; // minimalne V dla którego się spotkają

                    if (V < Sorted_V[Sorted_V.size() - 1])
                    {
                        wyprzedone += 1;
                        continue;
                    }
                    else
                    {
                        if (Time_to_connect[i + 1] >= time)
                        {
                            wyprzedone += 1;
                            continue;
                        }
                        double distans = poz[i + 1].poz_start - poz[i + 1].dl;
                        double timer = 0;
                        for (int j = i + 1; j <= index; j++)
                        {
                            if (Time_to_connect[j] == 0)
                            {
                                distans += poz[j].v * (time - timer);
                                break;
                            }
                            else if (Time_to_connect[j] != 0)
                            {
                                if (timer <= Time_to_connect[j])
                                {
                                    if (Time_to_connect[j] <= time)
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
                        }

                        if (distans - pocz_pierwszej >= D)
                            wyprzedone += 1;
                        continue;
                    }
                }
            }
        }
    }

    // gdy V_1 <= V_2
    for (int i = index; i < n; i++)
    {
        double time = (poz[i].poz_start + D) / (V_auto - poz[i].v);
        double pocz_pierwszej = poz[i].poz_start + poz[i].v * time;
        double kon_drugiej = poz[i + 1].poz_start - poz[i + 1].dl + poz[i + 1].v * time;
        if (kon_drugiej - pocz_pierwszej >= D)
            wyprzedone += 1;
    }
    cout << wyprzedone;
    return 0;
}