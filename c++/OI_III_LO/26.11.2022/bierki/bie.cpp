#include <bits/stdc++.h>

using namespace std;
inline bool sorto(int a, int b) { return a < b; }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> B(n);
    for (int i = 0; i < n; i++)
        cin >> B[i];
    sort(B.begin(), B.end(), sorto);
    int l = 0, r = 2, suma = B[0] + B[1];
    while (r < B.size()-1)
    {
        if (suma > B[r])
        {
            suma += B[r];
            r++;
        }
        else
        {
            suma -= B[l];
            l++;
            suma += B[r];
            r++;
        }
    }
    cout << B.size()-l;
    return 0;
}