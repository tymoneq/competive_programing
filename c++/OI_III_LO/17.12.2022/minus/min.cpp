#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int res = 0;
    string znak;
    cin >> znak;
    int head = 0, tail = 0, tmp_minus = 0, aktual_res = 0, minus_count = 0, remove_min = 0;
    while (head < znak.size())
    {
        if (znak[head] == '-')
        {
            tmp_minus++;

            if (tmp_minus == 2)
            {
                aktual_res++;
                tmp_minus = 0;
                res = max(res, aktual_res);
            }
            head++;
        }
        else if (znak[head] == '+')
        {
            if (tmp_minus == 0)
            {
                aktual_res++;
                head++;
                res = max(res, aktual_res);
            }
            else
            {
                tail = head - 1;
                aktual_res = 0;
                remove_min = 0;
                while (tail >= 0)
                {
                    if (znak[tail] == '-')
                    {
                        remove_min++;
                        if (remove_min == 2)
                        {
                            aktual_res++;
                            remove_min = 0;
                        }
                    }
                    else if (znak[tail] == '+' && remove_min == 0)
                        aktual_res++;
                    else if (znak[tail] == '+' && remove_min != 0)
                        break;
                    tail--;
                }

                aktual_res++;
                head++;
                tmp_minus = 0;
                res = max(res, aktual_res);
            }
        }
    }
    cout << res;
    return 0;
}