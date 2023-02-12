#include <bits/stdc++.h>
using namespace std;
// m[i][j] = min(m[i][j-1], m[i+(1<<(j-1))][j-1])
constexpr int LOGM = 5, N = 100;
int m[100][5];
int main()
{
    for (int j = 1; j < LOGM - 1; j++)
        for (int i = 0; i + (1 << j) - 1 < N; i++)
            m[i][j] = min(m[i][j - 1], m[i + (1 << (j - 1))][j - 1]);
    // mogą na siebie zachodzić
    // szykasz poprzedniej potęgi 2
    // len = R-L+1
    // j= log2(len)
    // return min(m[L][j], m[R-(1<<j)+1][j])
}