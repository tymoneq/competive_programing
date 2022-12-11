#include <bits/stdc++.h>
// Tymon Tumialis
using namespace std;
typedef long long ll;
constexpr int MAX_VAl = 20;

struct fall_domin
{
    int left = 0;
    int right = 0;
    int index = 0;
};

ll cost_of_move[MAX_VAl];
ll Height_of_element[MAX_VAl];
ll Pref_sum_right[MAX_VAl];
ll Pref_sum_left[MAX_VAl];
fall_domin Faling_domins[MAX_VAl];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, h, h1, h2;
    ll x, n1, n2, res = 0, prev = 0, tmp = 0;
    cin >> n;
    // reading date
    for (int i = 0; i < n; i++)
    {
        cin >> x >> h;

        Height_of_element[i] = h;
        Pref_sum_right[i] = x;
        if (i != 0)
            cost_of_move[i - 1] = x - prev;
        prev = x;
    }
    // Calculating Pref_sum
    for (int i = n - 2; i >= 0; i--)
        Pref_sum_left[i] = Pref_sum_left[i + 1] + cost_of_move[i];

    for (int i = 1; i < n; i++)
    {
        Faling_domins[i].index = i;
        if (cost_of_move[i - 1] - Height_of_element[i] <= 0)
        {
            Faling_domins[i].left = Faling_domins[i - 1].left + 1;
        }
    }

    for (int i = n - 2; i >= 0; i--)
        if (cost_of_move[i] - Height_of_element[i] <= 0)
        {
            tmp = Height_of_element[i] + Pref_sum_right[i];
            Faling_domins[i].right = Faling_domins[i + 1].right + 1;
        }

    cin >> n1 >> h1 >> n2 >> h2;

    return 0;
}