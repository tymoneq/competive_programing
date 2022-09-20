#include <iostream>
#include <string>

using namespace std;

int a, b, c, d;
int main()
{
    cin >> a >> b >> c;
    d = 2*a*c + 2*b*a + 2*b*c;
    cout << d;

    return 0;
}