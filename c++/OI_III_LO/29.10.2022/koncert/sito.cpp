#include <bits/stdc++.h>

using namespace std;
vector<int> sito()
{
    vector<int> v;
    vector<bool> table(numeric_limits<unsigned long long>::max(), 0);
    // int find = 0;
    // while (find < n)
    // {

    for (int i = 2; i * i <= numeric_limits<unsigned long long>::max(); i++)
    {
        if (table[i] == 1)
            continue;
        for (int j = i * i; j <= numeric_limits<unsigned long long>::max(); j += i)
        {
            table[j] = 1;
        }
    }

    for (int i = 2; i < numeric_limits<unsigned long long>::max(); i++)
    {
        if (table[i] == 0)
            v.push_back(i);
    }
    return v;
}

int main()
{
    int n;
    cin >> n;
    int i = 0;
    vector<int> V = sito();
    for (auto el : V)
    {
        if (i == n)
            break;
        cout << el << "\n";
        i++;
    }

    return 0;
}
