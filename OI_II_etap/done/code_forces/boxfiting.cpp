#include <bits/stdc++.h>

using namespace std;

constexpr int N = 20;
int Levels[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, W, w, tmp;
    cin >> t;

    for (int T = 0; T < t; T++)
    {
        cin >> n >> W;

        for (int i = 0; i < n; i++)
        {
            cin >> w;
            tmp = log2(w);
            Levels[tmp]++;
        }

        int height = 1, space_left = W;

        for (int iter = 0; iter < n; iter++)
        {
            int largest = -1;

            for (int size = 19; size >= 0; size--)
            {
                if (Levels[size] and (1 << size) <= space_left)
                {
                    largest = size;
                    break;
                }
            }

            if (largest == -1)
            {
                space_left = W;
                height++;
                for (int size = 19; size >= 0; size--)
                {
                    if (Levels[size] and (1 << size) <= space_left)
                    {
                        largest = size;
                        break;
                    }
                }
            }

            Levels[largest] -= 1;
            space_left -= 1 << largest;
        }

        cout << height << "\n";
    }
    return 0;
}