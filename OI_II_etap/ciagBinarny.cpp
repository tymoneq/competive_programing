#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q, l, r, k;

    cin >> n >> q;
    vector<int> A(n + 1);
    vector<int> Jedynki(n + 1);
    vector<int> endOfRange(n + 2);
    vector<int> Specjalne(n + 1);
    endOfRange[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
        endOfRange[i + 1] = A[i] + endOfRange[i];

        if (i % 2 == 1)
            Jedynki[i] += A[i];

        Jedynki[i] += Jedynki[i - 1];
    }

    for (int i = 2; i <= n; i += 2)
    {
        Specjalne[1] = 1;
        Specjalne[i] = 1;
        if (i != n)
            Specjalne[i]++;
    }

    for (int i = 1; i <= n; i++)
        Specjalne[i] += Specjalne[i - 1];

    while (q--)
    {
        int res = 0;
        cin >> l >> r >> k;

        auto it_begin = upper_bound(endOfRange.begin(), endOfRange.end(), l);
        auto it_end = upper_bound(endOfRange.begin(), endOfRange.end(), r);

        it_begin--;

        // sprawdzanie które elementy nie leżą w pewłnym przedziale
        int not_in_range = 0, not_special = 0;
        if ((it_begin - endOfRange.begin()) % 2 == 1)
            not_in_range += *it_begin - l;

        if (l == *it_begin - A[(it_begin - endOfRange.begin())])
            not_special++;

        if ((it_end - endOfRange.begin()) % 2 == 1)
            not_in_range += *it_end - r;

        if ((it_end - endOfRange.begin()) != n)
            not_special++;

        it_end--;
        // policzenie ile jedynek nie jest w przedziale
        res = Jedynki[(it_end - endOfRange.begin())] - Jedynki[(it_begin - endOfRange.begin()) - 1] - not_in_range;
        int spec = Specjalne[(it_end - endOfRange.begin())] - Specjalne[(it_begin - endOfRange.begin()) - 1] - not_special;
        res = res - spec + min(spec, k);

        cout << res << "\n";
    }

    return 0;
}
