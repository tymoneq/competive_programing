#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;

    while (cin >> n >> m)
    {
        const int M = m;
        vector<int> cycle;
        cycle.push_back(m);
        int max = 0;
        while (m != 1)
        {

            if (m % 2 == 0)
            {
                m /= 2;
                cycle.push_back(m);
            }
            else
            {
                m = m * 3 + 1;
                cycle.push_back(m);
            }
        }
        cout << n << " " << M << " " << cycle.size() << "\n";
    }
    return 0;
}