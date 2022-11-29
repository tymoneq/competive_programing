#include <bits/stdc++.h>

using namespace std;
void upd(int v, int x, vector<int> &Tree)
{
    Tree[v] = x;
    int tmp = v / 2;
    while (tmp > 0)
    {
        Tree[tmp] = Tree[tmp * 2] + Tree[tmp * 2 + 1];
        tmp /= 2;
    }
}
int get_value(int l, int r, vector<int> &Tree)
{
    int sum = 0;
    l -= 1;
    r += 1;
    if (l == -1 && r == Tree.size())
        sum = Tree[1];
    else
    {
        if (l == -1)
        {
            while (r / 2 != 1)
            {
                if (r % 2 == 0)
                    sum += Tree[r - 1];
                r /= 2;
            }

            sum += Tree[2];
        }
        else if (r == Tree.size())
        {
            while (l / 2 != 1)
            {
                if (l % 2 == 0)
                    sum += Tree[l + 1];

                l /= 2;
            }
            sum += Tree[3];
        }
        else
        {
            while (l / 2 != r / 2)
            {
                if (l % 2 == 0)
                    sum += Tree[l + 1];
                l /= 2;

                if (r % 2 == 1)
                    sum += Tree[r - 1];
                r /= 2;
            }
        }
    }
    return sum;
}
int main()
{
    int n;
    cin >> n;
    int tmp = log2(n);
    int base = pow(2, tmp);
    if (base != n)
        base++;
    vector<int> Tree(base * 2);
    for (int i = base; i < base + n; i++)
        cin >> Tree[i];

    for (int i = base - 1; i > 0; i--)
    {
        int suma = Tree[2 * i] + Tree[2 * i + 1];
        Tree[i] = suma;
    }
    upd(11, -10, Tree);
    int sum = get_value(11, 15, Tree);
    return 0;
}