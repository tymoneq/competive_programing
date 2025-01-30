#include "wydlib.h"

#include <bits/stdc++.h>

using namespace std;

// 0 jest na tym polu
// 1 jest nad
// 2 jest pod
// 3 jest po lewej
// 4 jest po prawej

std::vector<std::vector<int>> Bitek(int n, std::array<int, K> A, std::array<int, K> B)
{
    vector<vector<int>> Uczelnia(n, vector<int>(n, 1));
    int powerOffive = 1;
    
    for (int i = 0; i < K; i++)
    {
        // u góry
        for (int j = A[i] - 1; j >= 0; j--)
            for (int x = 0; x < n; x++)
                Uczelnia[j][x] += 2 * powerOffive;

        // w dół

        for (int j = A[i] + 1; j < n; j++)
            for (int x = 0; x < n; x++)
                Uczelnia[j][x] += 1 * powerOffive;

        // w lewo
        for (int j = B[i] - 1; j >= 0; j--)
            Uczelnia[A[i]][j] += 4 * powerOffive;

        // w prawo

        for (int j = B[i] + 1; j < n; j++)
            Uczelnia[A[i]][j] += 3 * powerOffive;

        powerOffive *= 5;
    }

    return Uczelnia;
}

array<int, K> decode(int a)
{
    vector<int> Id;

    map<int, int> code;
    code[0] = 4;
    code[1] = 3;
    code[2] = 2;
    code[3] = 1;
    code[4] = 0;

    while (a > 0)
    {
        Id.push_back(a % 5);
        a /= 5;
    }

    array<int, 7> ans;

    for (int i = 0; i < 7; i++)
    {
        ans[i] = code[Id[i]];
    }

    return ans;
}

std::array<int, K> Bajtazar(std::array<int, 9> A)
{
    array<int, K> ans;

    ans = decode(A[4] - 1);

    return ans;
}
