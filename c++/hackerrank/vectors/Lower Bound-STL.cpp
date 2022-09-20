#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, q, a, b;

void getIndex(vector<int> v, int k)
{
    auto it = find(v.begin(), v.end(), k);
    if (it != v.end())
    {

        int index = it - v.begin();
        cout << "Yes"
             << " " << index + 1 << endl;
    }
    else
    {
        for (int i = k; i > 0; i++)
        {
            auto it = find(v.begin(), v.end(), i);
           
            if (it != v.end())
            {
                int index = it - v.begin();
                cout << "No" << " " << index+1 << endl;
                break;
            }
        }
    }
}
int main()
{
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        v.push_back(b);
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> a;
        getIndex(v, a);
    }
    return 0;
}
