#include <bits/stdc++.h>
using namespace std;

int arr[10];
int bin_s(int v, int n)
{
    int L = 0, R = n - 1, mid;
    while (L <= R)
    {
        mid = L + (R - L) / 2;
        if (arr[mid] == v)
            return mid;
        if (arr[mid] < v)
            L = mid + 1;
        else
            R = mid - 1;
    }
    return -1;
}
int lower_b(int v, int n)
{
    int l = 0, r = n - 1, ans = -1, mid = 0;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (arr[mid] >= v)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}