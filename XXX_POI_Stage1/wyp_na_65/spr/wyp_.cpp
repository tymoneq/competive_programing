#include <bits/stdc++.h>

using namespace std;

struct track
{
    double poz_start = 0;
    double dl = 0;
    double v = 0;
};
inline bool sorto(track &lhs, track &rhs) { return lhs.v > rhs.v; }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, wyprzedone = 1;
    double V_auto, W, M, D;
    cin >> n >> D >> W >> M;
    pair<double, int> V_mal; // first = V second = index
    vector<track> poz(n + 1);
    vector<track> Sorted_V(n);
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
        Sorted_V[i - 1] = l;
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
    vector<double> Time_to_connect(index, 0);
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
        double min_v;
        for (int i = index - 1; i >= 1; i--)
        {
            if (poz[i].v <= min_v)
            {
                Time_to_connect[i] = 0;
                if (poz[i].v < min_v)
                    min_v = poz[i].v;
            }
            else
            {
                double time = (poz[i+1].poz_start - poz[i+1].dl - poz[i].poz_start) / (poz[i].v);
            }
        }
    }

    // licz czas
    if (must_check)
    {
        // gdy V_1> V_2
        // sprawdzaj dystans między nimi i jakie musiałoby być V żeby się dogoniły i gdzie występuje to V
        for (int i = 1; i < index; i++)
        {
            if (Distance_b_tracks[i] == 1)
                continue;
            if (i == index - 1)
            {
                double time = (poz[i].poz_start + D) / (V_auto - poz[i].v);
                double pocz_pierwszej = poz[i].poz_start + poz[i].v * time;
                double kon_drugiej = poz[i + 1].poz_start - poz[i + 1].dl + poz[i + 1].v * time;
                if (kon_drugiej - pocz_pierwszej >= D)
                    wyprzedone += 1;
                continue;
            }
            double time = (poz[i].poz_start + D) / (V_auto - poz[i].v);
            double pocz_pierwszej = poz[i].poz_start + poz[i].v * time;
            double kon_drugiej = poz[i + 1].poz_start - poz[i + 1].dl + poz[i + 1].v * time;
            if (pocz_pierwszej + D <= poz[i + 1].poz_start - poz[i + 1].dl)
                wyprzedone += 1;

            else if (kon_drugiej - pocz_pierwszej >= D)
            {
                double V = (D + pocz_pierwszej - poz[i + 1].poz_start + poz[i + 1].dl) / time;
                if (V < Sorted_V[Sorted_V.size() - 1].v)
                    wyprzedone += 1;
                else
                {
                    int XD = 0;
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