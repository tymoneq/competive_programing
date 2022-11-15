#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;
// C++ Program to find n'th fibonacci Number
ull fib(ull n)
{
    double phi = (1 + sqrt(5)) / 2;
    return round(pow(phi, n) / sqrt(5));
}
/*
// C++ Program to find n'th fibonacci Number in
// with O(Log n) arithmetic operations

const int MAX = 1000;

// Create an array for memoization
int f[MAX] = {0};

// Returns n'th fibonacci number using table f[]
int fib(int n)
{
    // Base cases
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return (f[n] = 1);

    // If fib(n) is already computed
    if (f[n])
        return f[n];

    int k = (n & 1) ? (n + 1) / 2 : n / 2;

    // Applying above formula [Note value n&1 is 1
    // if n is odd, else 0.
    f[n] = (n & 1) ? (fib(k) * fib(k) + fib(k - 1) * fib(k - 1))
                   : (2 * fib(k - 1) + fib(k)) * fib(k);

    return f[n];
}

 Driver program to test above function
int main()
{
    int n = 9;
    printf("%d ", fib(n));
    return 0;
}
*/

// Driver Code
int main()
{
    ull n;
    cin >> n;
    std::cout << fib(n) << std::endl;
    return 0;
}
// This code is contributed by Lokesh Mohanty.
