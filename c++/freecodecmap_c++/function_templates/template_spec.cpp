#include <bits/stdc++.h>

using namespace std;

template <typename T>
T maximum(T a, T b)
{
    return (a > b) ? a : b;
}
template <>
const char *maximum<const char *>(const char *a, const char *b)
{
    return (strcmp(a, b) > 0) ? a : b;
}
int main()
{
    int a{10}, b{435};
    double c{44.6}, d{556.7};
    string e{"Hello"}, f{"World"};

    const char* j{"wild"};
    const char* h{"animal"};

    auto result = maximum(j,h);
    cout << result;
    return 0;
}