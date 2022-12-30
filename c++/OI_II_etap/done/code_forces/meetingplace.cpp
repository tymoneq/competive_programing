#include <bits/stdc++.h>
using namespace std;
const int M = 6e4 + 10;
const double EPS = 1e-7;
int Poz[M], V[M], n;

bool can_meet(double time)
{
    double l = 0, r = 1e9, street, lewo, prawo;
    for (int i = 0; i < n; i++)
    {
        street = (double)V[i] * time;
        lewo = (double)Poz[i] - street;
        prawo = (double)Poz[i] + street;
        l = max(l, lewo);
        r = min(prawo, r);
    }
    if (l > r)
        return 0;
    else
        return 1;
}

double BS(double l, double r)
{
    double mid;
    while (r - l > EPS)
    {
        mid = (l + r) / 2;
        if (can_meet(mid))
            r = mid;
        else
            l = mid;
    }
    return l;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> Poz[i];

    for (int i = 0; i < n; i++)
        cin >> V[i];

    cout.precision(12);
    cout << fixed << BS(0, 1e9);
    return 0;
}