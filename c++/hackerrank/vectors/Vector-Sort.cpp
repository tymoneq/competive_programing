#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, a;
int main()
{
    vector<int> v;
    cin >> n;
    while (cin >> a)
    {

        v.push_back(a);
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
