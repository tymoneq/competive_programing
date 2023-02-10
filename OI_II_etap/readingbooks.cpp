#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> Books(n);
    for (int i = 0; i < n; i++)
        cin >> Books[i];
    sort(Books.begin(), Books.end());
    int l = 0, r = n - 1;
    long long timel = 0, timer = 0;
    while (l <= r)
    {
        if (timel + Books[l] <= timer + Books[r])
        {
            timel += Books[l];
            l++;
        }
        else
        {
            timer += Books[r];
            r--;
        }
    }
    cout << max(timel, timer) * 2;
}