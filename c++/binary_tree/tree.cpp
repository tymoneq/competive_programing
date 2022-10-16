#include <bits/stdc++.h>

using namespace std;

struct tree
{
    int val;
    int left = 0;
    int right = 0;
};

int main()
{
    int n;
    cin >> n;
    tree T[n];
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a == 0)
            T[i].val = a;

        else
        {
            T[i].val = a;
            int fat = (a - 1) / 2;
            if (T[fat].left == 0)
                T[fat].left = a;
            else
                T[fat].right = a;
        }
    }
    for (auto el : T)
    {
        cout << el.left << " " << el.val << " " << el.right << "\n";
    }
    return 0;
}