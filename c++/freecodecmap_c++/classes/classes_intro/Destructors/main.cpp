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

void some_func()
{
    Dog *p_dog = new Dog("Fluffy", "Shepher", 2);

    delete p_dog;
}

int main()
{

    some_func();
    cout << "Done "
         << "\n";

    return 0;
}