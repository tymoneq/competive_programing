#include <bits/stdc++.h>

using namespace std;

/* A class is a blueprint for an object */
class Dog
{
public:
    Dog() = default;
    Dog(string_view name_param, string_view breed_param, int age_param)
    {
        name = name_param;
        breed = breed_param;
        p_age = new int;
        *p_age = age_param;
    }
    ~Dog()
    {
        delete p_age;
        cout << "Dog destructor called for : " << name << "\n";
    }

private:
    string name;
    string breed;
    int *p_age{nullptr};
};


int main()
{

    Dog dog1("Fluffy1", "Shepher", 2);
    Dog dog2("Fluffy2", "Shepher", 5);
    Dog dog3("Fluffy3", "Shepher", 6);
    Dog dog4("Fluffy4", "Shepher", 7);
    
    cout << "Done "
         << "\n";

    return 0;
}