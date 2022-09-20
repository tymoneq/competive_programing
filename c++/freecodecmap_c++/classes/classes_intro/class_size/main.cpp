#include <bits/stdc++.h>

using namespace std;

class Dog
{
public:
    Dog() = default;

private:
    size_t leg_count{4};
    size_t arm_count;
    int *p_age;
};
int main()
{
    Dog dog1;
    cout << sizeof(dog1) << "\n";
    return 0;
}