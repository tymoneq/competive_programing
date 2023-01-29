#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 7;
int d[M];
ofstream file;
ifstream file_from;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    file.open("planting.out");
    file_from.open("planting.in");
    int a, b, N;
    file_from >> N;
    for (int i = 1; i < N; i++)
    {
        file_from >> a >> b;
        d[a - 1]++, d[b - 1]++;
    }
    int D = 0;
    for (int i = 0; i < N; i++)
        if (d[i] > D)
            D = d[i];
    file << D + 1 << "\n";
    file.close();
    file_from.close();
    return 0;
}