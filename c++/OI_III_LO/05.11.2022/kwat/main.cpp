#include <bits/stdc++.h>

using namespace std;
inline bool sort_2(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}
inline bool sort_3(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int C, Z, N, T, wynik_1 = 0, wynik_2 = 0, wynik_3 = 0;
    cin >> C >> Z >> N >> T;
    const int c = C, z = Z, n = N;
    vector<vector<int>> V(T);
    for (int i = 0; i < T; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        V[i].push_back(a);
        V[i].push_back(b);
        V[i].push_back(c);
    }
    make_heap(V.begin(), V.end());
    for (int i = T - 1; i >= 0; i--)
    {
        if (V[i][0] <= C && V[i][1] <= Z && V[i][2] <= N)
        {
            wynik_1 += 1;
            C -= V[i][0];
            Z -= V[i][1];
            N -= V[i][2];
        }
    }
    sort_heap(V.begin(), V.end());
    make_heap(V.begin(), V.end(), sort_2);
    C = c;
    Z = z;
    N = n;
    for (int i = T - 1; i >= 0; i--)
    {
        if (V[i][0] <= C && V[i][1] <= Z && V[i][2] <= N)
        {
            wynik_2 += 1;
            C -= V[i][0];
            Z -= V[i][1];
            N -= V[i][2];
        }
    }
    sort_heap(V.begin(), V.end());
    make_heap(V.begin(), V.end(), sort_3);
    C = c;
    Z = z;
    N = n;
    for (int i = T - 1; i >= 0; i--)
    {
        if (V[i][0] <= C && V[i][1] <= Z && V[i][2] <= N)
        {
            wynik_3 += 1;
            C -= V[i][0];
            Z -= V[i][1];
            N -= V[i][2];
        }
    }
    cout << max(wynik_1, max(wynik_2, wynik_3));
    return 0;
}
