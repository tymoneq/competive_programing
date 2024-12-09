#include <bits/stdc++.h>

using namespace std;

int losuj(int a, int b)
{
    return a + rand() % (b - a + 1);
}

int main()
{
    int ziarno;
    cin >> ziarno;
    srand(ziarno);

    int n = losuj(1, 10);
    int k = losuj(1, 5);

    cout << n << " " << k << '\n';

    for (int i = 1; i <= n; i++)
        cout << losuj(1, 20) << ' ';

    cout << '\n';

    vector<int> perm(n + 1);
    for (int i = 1; i <= n; i++)
        perm[i] = i;

    random_shuffle(perm.begin() + 1, perm.end());
    vector<pair<int, int>> kraw;
    for (int i = 2; i <= n; i++)
    {
        int rodzic = losuj(1, i - 1);
        kraw.emplace_back(perm[rodzic], perm[i]);
    }

    random_shuffle(kraw.begin(), kraw.end());
    for (auto el : kraw)
    {
        if (rand() % 2 == 1)
            swap(el.first, el.second);

        cout << el.first << " " << el.second << '\n';
    }

    return 0;
}