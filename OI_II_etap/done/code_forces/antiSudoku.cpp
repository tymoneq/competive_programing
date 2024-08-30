#include <bits/stdc++.h>

using namespace std;

constexpr int N = 9;

int GRAF[N][N];
bool USEDY[N], S[3];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, a;
    cin >> t;

    while (t--)
    {
        for (int i = 0; i < N; i++)
        {
            USEDY[i] = 0;
            cin >> a;
            for (int j = N - 1; j >= 0; j--)
            {
                GRAF[i][j] = a % 10;
                a /= 10;
            }
        }

        int num = 0;
        for (int i = 1; i <= 9; i++)
            if (i != GRAF[0][0] && i != GRAF[8][8])
            {
                num = i;
                break;
            }

        for (int k = 0; k < 3; k++)
        {
            for (int i = 0; i < 3; i++)
                S[i] = 0;
            for (int i = k * 3; i < 3 + (3 * k); i++)
                for (int j = 0; j < N; j++)
                    if (!USEDY[j] && GRAF[i][j] != num && !S[j / 3]) // sprawdzenie pprostokąta
                    {
                        USEDY[j] = 1;
                        GRAF[i][j] = num;
                        S[j / 3] = 1;
                        break;
                    }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << GRAF[i][j];

            cout << "\n";
        }
    }

    return 0;
}