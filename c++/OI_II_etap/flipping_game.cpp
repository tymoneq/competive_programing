#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, num_of_0 = 0, num_of_1 = 0, l = -1, r = 0, aktual_sum = 0, res = 0;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    for (int i = 0; i < n; i++)
    {
        if (numbers[i] == 1)
            aktual_sum++;
        else
        {
            l = i;
            num_of_0++;
            break;
        }
    }
    int i = l + 1;
    while (l < n)
    {
        if (numbers[i] == 1)
        {
            if (num_of_0 <= num_of_1)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if(numbers[j] == 1)
                        aktual_sum++;
                   
                }
            }
            num_of_1++;
        }

        else
        {
            num_of_0++;
        }
        i++;
    }
    return 0;
}