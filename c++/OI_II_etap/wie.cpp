#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_VAL = 200000;
typedef long long ll;

ll cost_of_move[MAX_VAL];
int Height_of_element[MAX_VAL];
ll Right_dominos_which_falls[MAX_VAL];
ll Left_dominos_which_falls[MAX_VAL];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, h, H1, H2, res = 0;
    ll x, N1, N2, prev = 0, current = 0, left_range = 0, index_left = 0, right_range = 0, right_index = 0;
    cin >> n;
    vector<ll> Pref_sum_right(n);
    vector<ll> Pref_sum_left(n);
    for (int i = 0; i < MAX_VAL; i++)
    {
        Right_dominos_which_falls[i] = numeric_limits<ll>::max();
        Left_dominos_which_falls[i] = numeric_limits<ll>::max();
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x >> h;

        Height_of_element[i] = h;
        Pref_sum_right[i] = x;
        if (i != 0)
            cost_of_move[i - 1] = x - prev;
        prev = x;
    }
    cin >> N1 >> H1 >> N2 >> H2;
    if (H1 < H2)
    {
        ll tmp = H1, tmp1 = N1;
        H1 = H2;
        N1 = N2;
        N2 = tmp1;
        H2 = tmp;
    }
    for (int i = n - 2; i >= 0; i--)
        Pref_sum_left[i] = Pref_sum_left[i + 1] + cost_of_move[i];

    for (int i = 1; i < n; i++)
    {
        left_range = Pref_sum_left[i] + Height_of_element[i];
        auto itr = lower_bound(Pref_sum_left.begin(), Pref_sum_left.end(), left_range, greater<int>());
        itr--;
        index_left = itr - Pref_sum_left.begin();
        for (auto j = index_left; j < i; j++)
        {
            if (Left_dominos_which_falls[j] == 0)
                break;
            if (Pref_sum_left[j] - left_range > 0)
                Left_dominos_which_falls[j] = min(Pref_sum_left[j] - left_range, Left_dominos_which_falls[j]);
            else
                Left_dominos_which_falls[j] = 0;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        right_range = Pref_sum_right[i] + Height_of_element[i];
        auto itr = lower_bound(Pref_sum_right.begin(), Pref_sum_right.end(), right_range);
        right_index = itr - Pref_sum_right.begin();
        for (int j = right_index; j > i; j--)
        {
            if (Right_dominos_which_falls[j] == 0)
                break;
            if (Pref_sum_right[j] - right_range > 0)
                Right_dominos_which_falls[j] = min(Pref_sum_right[j] - right_range, Right_dominos_which_falls[j]);
            else
                Right_dominos_which_falls[j] = 0;
        }
    }
    // indexy są pokazują ile potrzeba żeby dany element się przewrócił !!!!
    int colected = 0, tmp_res = 0, skipped = 0;
    ll H = 0, L = 0, mod_H = 0, mod_l = 0, n1 = N1, n2 = N2; // H-wysokie l -niskie
    bool new_val = false;
    if (n == 1)
    {
        cout << 1 + N1 + N2;
        return 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        colected = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (Right_dominos_which_falls[j] == 0)
                colected++;
            else
            {
                if (!new_val)
                {
                    skipped = j;
                    new_val = 1;
                }

                H = Right_dominos_which_falls[j] / H1;
                mod_H = Right_dominos_which_falls[j] % H1;
                if (H > n1)
                {
                    L = (Right_dominos_which_falls[j] - H1 * n1) / H2;
                    mod_l = (Right_dominos_which_falls[j] - H1 * n1) % H2;
                    if (mod_l != 0)
                        L++;
                }
                else if (mod_H != 0)
                {
                    L = (Right_dominos_which_falls[j] - H1 * H) / H2;
                    mod_l = (Right_dominos_which_falls[j] - H1 * H) % H2;
                    if (mod_l != 0)
                        L++;
                }
                if (H > n1 && L > n2)
                {
                    tmp_res += colected + n1 + n2;
                    break;
                }
                n1 -= H;
                n2 -= L;
                tmp_res += colected + H + L;
                colected = 1;
            }
        }
        n1 = N1;
        n2 = N2;
        res = max(res, tmp_res);
        tmp_res = 0;
        i = skipped - 1;
        new_val = 0, L = 0, H = 0, mod_H = 0, mod_l = 0;
    }

    for (int i = n - 2; i > 0; i--)
    {
        colected = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (Left_dominos_which_falls[j] == 0)
                colected++;
            else
            {
                if (!new_val)
                {
                    skipped = j;
                    new_val = 1;
                }

                H = Left_dominos_which_falls[j] / H1;
                mod_H = Right_dominos_which_falls[j] % H1;
                if (H > n1)
                {
                    L = (Left_dominos_which_falls[j] - H1 * n1) / H2;
                    mod_l = (Left_dominos_which_falls[j] - H1 * n1) % H2;
                    if (mod_l != 0)
                        L++;
                }
                else if (mod_H != 0)
                {
                    L = (Left_dominos_which_falls[j] - H1 * H) / H2;
                    mod_l = (Left_dominos_which_falls[j] - H1 * H) % H2;
                    if (mod_l != 0)
                        L++;
                }
                if (H > n1 && L > n2)
                {
                    tmp_res += colected + n1 + n2;
                    break;
                }
                n1 -= H;
                n2 -= L;
                tmp_res += colected + H + L;
                colected = 1;
            }
        }
        n1 = N1;
        n2 = N2;
        res = max(res, tmp_res);
        tmp_res = 0;
        i = skipped - 1;
        new_val = 0, L = 0, H = 0, mod_H = 0, mod_l = 0;
    }
    cout << res;
    return 0;
}