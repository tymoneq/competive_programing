#include <bits/stdc++.h>

using namespace std;
struct Cow
{
    int l, r;
};

bool operator<(const Cow &a, const Cow &b)
{
    return a.l < b.l;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("lifeguards.in", "r", stdin);

    int n;
    cin >> n;
    vector<Cow> cow(n);
    for (int i = 0; i < n; i++)
        cin >> cow[i].l >> cow[i].r;

    sort(cow.begin(), cow.end());
    int total_time = 0, left = 0, right = 0;
    for (int i = 0; i < n; i++)
        if (cow[i].r > right)
        {
            left = max(right, cow[i].l);
            total_time += cow[i].r - left;
            right = cow[i].r;
        }

    Cow last;
    last.l = cow[n - 1].r;
    cow.push_back(last);
    int min_alone_time = total_time, c;
    right = 0;
    for (int i = 0; i < n; i++)
    {
        c = min(cow[i + 1].l, cow[i].r) - max(cow[i].l, right);
        min_alone_time = min(min_alone_time, c);
        right = max(right, cow[i].r);
    }
    freopen("lifeguards.out", "w", stdout);
    cout << total_time - max(min_alone_time, 0);

    return 0;
}