#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int MAX_VAL = 200001;

ll Posiotion[MAX_VAL];
int Height[MAX_VAL];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, H1, H2, l = 0, r = 1;
    ll N1, N2, res = 0, tmp_res = 0;
    vector<pair<int, int>> To_collect_right; // first początek second koniec przedziału
    vector<ll> Distans_to_add_right;
    vector<pair<int, int>> To_collect_left; // first początek second koniec przedziału
    vector<ll> Distans_to_add_left;
    cin >> n;
    Posiotion[n] = numeric_limits<ll>::max();
    for (int i = 0; i < n; i++)
        cin >>
            Posiotion[i] >> Height[i];
    cin >> N1 >> H1 >> N2 >> H2;
    if (n == 1)
    {
        cout << n + N1 + N2;
        return 0;
    }
    if (H1 < H2)
    {
        ll tmp_1 = H1, tmp_2 = N1;
        N1 = N2;
        H1 = H2;
        H2 = tmp_1;
        N2 = tmp_2;
    }
    int glowa = 0, ogon = 0;
    ll a_range = Height[0] + Posiotion[0];
    while (glowa < n)
    {
        if (max(a_range, Height[glowa] + Posiotion[glowa]) >= Posiotion[glowa + 1])
        {
            glowa++;
            a_range = max(a_range, Height[glowa] + Posiotion[glowa]);
        }
        else
        {
            a_range = max(a_range, Height[glowa] + Posiotion[glowa]);
            To_collect_right.push_back(make_pair(ogon, glowa));
            Distans_to_add_right.push_back(Posiotion[glowa + 1] - a_range);
            glowa++;
            ogon = glowa;
            a_range = 0;
        }
    }
    glowa = n - 1, ogon = n - 1, a_range = Posiotion[n - 1] - Height[n - 1];
    while (glowa >= 0)
    {
        if (glowa == 0)
        {
            To_collect_left.push_back(make_pair(glowa, ogon));
            Distans_to_add_left.push_back(numeric_limits<ll>::max());
            break;
        }
        if (max(a_range, Posiotion[glowa] - Height[glowa]) <= Posiotion[glowa - 1])
        {
            glowa--;
            a_range = max(a_range, Posiotion[glowa] - Height[glowa]);
        }
        else
        {
            a_range = max(a_range, Posiotion[glowa] - Height[glowa]);
            To_collect_left.push_back(make_pair(glowa, ogon));
            Distans_to_add_left.push_back(a_range - Posiotion[glowa - 1]);
            glowa--;
            ogon = glowa;
            a_range = 0;
        }
    }
    ll H, h_mod, L, l_mod, n1 = N1, n2 = N2;
    glowa = 0, ogon = 0;
    while (glowa < Distans_to_add_right.size())
    {

        tmp_res += To_collect_right[glowa].second - To_collect_right[glowa].first + 1;
        H = Distans_to_add_right[glowa] / H1;
        h_mod = Distans_to_add_right[glowa] % H1;
        if (H > n1)
        {
            L = (Distans_to_add_right[glowa] - H1 * n1) / H2;
            l_mod = (Distans_to_add_right[glowa] - H1 * n1) % H2;
            if (l_mod != 0)
                L++;
            if (L > n1)
            {
                tmp_res += n1 + n2;
                res = max(res, tmp_res);
                tmp_res -= To_collect_right[ogon].second - To_collect_right[ogon].first + 1;
                tmp_res -= To_collect_right[glowa].second - To_collect_right[glowa].first + 1;
                n1 += Distans_to_add_right[ogon] / H1;
                if (Distans_to_add_right[ogon] % H1 != 0)
                {
                    n2 += (Distans_to_add_right[ogon] - Distans_to_add_right[ogon] / H1) / H2;
                    if ((Distans_to_add_right[ogon] - Distans_to_add_right[ogon] / H1) % H2 != 0)
                        n2++;
                }
                ogon++;
                continue;
            }
            tmp_res += n1 + L;
            n1 = 0;
            n2 -= L;
        }
        else if (h_mod != 0)
        {
            L = (Distans_to_add_right[glowa] - H1 * H) / H2;
            l_mod = (Distans_to_add_right[glowa] - H1 * H) % H2;
            if (l_mod != 0)
                L++;
            if (L > n1)
            {
                tmp_res += n1 + n2;
                break;
            }
            tmp_res += H + L;
            n1 -= H;
            n2 -= L;
        }
        else
        {
            tmp_res += H;
            n1 -= H;
        }
        glowa++;
    }
    glowa = 0, ogon = 0;
    // while (glowa < Distans_to_add_left.size())
    // {
    //     tmp_res += To_collect_left[glowa].second - To_collect_left[glowa].first + 1;
    //     H = Distans_to_add_left[glowa] / H1;
    //     h_mod = Distans_to_add_left[glowa] % H1;
    //     if (H > n1)
    //     {
    //         L = (Distans_to_add_left[glowa] - H1 * n1) / H2;
    //         l_mod = (Distans_to_add_left[glowa] - H1 * n1) % H2;
    //         if (l_mod != 0)
    //             L++;
    //         if (L > n1)
    //         {
    //             tmp_res += n1 + n2;
    //             res = max(res, tmp_res);
    //             tmp_res -= To_collect_left[ogon].second - To_collect_left[ogon].first + 1;
    //             n1 += Distans_to_add_left[ogon] / H1;
    //             if (Distans_to_add_left[ogon] % H1 != 0)
    //             {
    //                 n2 += (Distans_to_add_left[ogon] - Distans_to_add_left[ogon] / H1) / H2;
    //                 if ((Distans_to_add_left[ogon] - Distans_to_add_left[ogon] / H1) % H2 != 0)
    //                     n2++;
    //             }
    //             ogon++;
    //             glowa++;
    //             continue;
    //         }
    //         tmp_res += n1 + L;
    //         n1 = 0;
    //         n2 -= L;
    //     }
    //     else if (h_mod != 0)
    //     {
    //         L = (Distans_to_add_left[glowa] - H1 * H) / H2;
    //         l_mod = (Distans_to_add_left[glowa] - H1 * H) % H2;
    //         if (l_mod != 0)
    //             L++;
    //         if (L > n1)
    //         {
    //             tmp_res += n1 + n2;
    //             break;
    //         }
    //         tmp_res += H + L;
    //         n1 -= H;
    //         n2 -= L;
    //     }
    //     else
    //     {
    //         tmp_res += H;
    //         n1 -= H;
    //     }
    //     glowa++;
    // }
    cout << res;
    return 0;
}