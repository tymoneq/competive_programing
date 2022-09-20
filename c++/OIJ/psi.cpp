#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int n, x, np, p, cp;
long long result;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x % 2 != 0)
        {
            np += 1;
            if (cp > 1)
            {
                for (int j = cp - 1; j > 0; j--)
                {
                    result+=j;
                }
            }
            cp = 0;
            if ((np > 1) && (p == 0))
            {
                if (np % 2 == 0)
                    result = pow((np / 2), 2);
                else
                    result = np - 1;
            }
            else if ((np % 2 == 0) && (p != 0))
            {
                result += 1;
            }
        }
        else
        {
            result += 1;
            p += 1;
            cp += 1;
            if ((np % 2 == 0) && (np != 0))
            {
                result += 1;
            }
        }
    }
    if (cp > 1)
            {
                for (int j = cp - 1; j > 0; j--)
                {
                    result+=j;
                }
            }
    cout << result;
    return 0;
}