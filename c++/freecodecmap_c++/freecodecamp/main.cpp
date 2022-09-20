#include <iostream>

using namespace std;
int main()
{
    auto result = (10 <=> 20) > 0;
    cout << result;

    return 0;
}