#include <bits/stdc++.h>

using namespace std;

void say_age(int *age)
{
    ++*age;
    cout << "Hello you are " << *age << " years odl" << " &age " << &age <<endl;
}

int main()
{
    int age{4};
    cout << "Age before " << age <<  " &age " << &age << endl;
    say_age(&age);
    cout << "Age after " << age <<  " &age " << &age << endl;

    return 0;
}