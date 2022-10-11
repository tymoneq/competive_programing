#include <bits/stdc++.h>

using namespace std;

void printt(const vector<int> &v)
{
    for (auto el : v)
    {
        cout << el << " ";
    }
}
vector<int> mySort(vector<int> v)
{
    sort(v.begin(), v.end());
    return v;
}

int main()
{

    vector<int> V = {5, 4, 3, 7, 8};
    V = mySort(V);
    printt(V);
    return 0;
}