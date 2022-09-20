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
        cout << "Dog : " << name << " constructed at " << this << "\n";
    }
    ~Dog()
    {
        delete p_age;
        cout << "Dog destructor called for : " << name << "\n";
    }
    // Pointers
    /*
    Dog *set_dog_name(string_view name)
    {
        this->name = name;
        return this;
    }

    Dog *set_dog_breed(string_view breed)
    {
        this->breed = breed;
        return this;
    }
    Dog *set_dog_age(int age)
    {
        *(this->p_age) = age;
        return this;
    }
    */

    // references
    Dog &set_dog_name(string_view name)
    {
        this->name = name;
        return *this;
    }

    Dog &set_dog_breed(string_view breed)
    {
        this->breed = breed;
        return *this;
    }
    Dog &set_dog_age(int age)
    {
        *(this->p_age) = age;
        return *this;
    }

    void print_info()
    {
        cout << "Dog(" << this << ") : [name : " << name << " \t age : " << *p_age << " breed : " << breed << "]\n";
    }

private:
    string name;
    string breed;
    int *p_age{nullptr};
};

int main()
{

    Dog p_dog("Fluffy", "Shepher", 2);
    cout << "Done "
         << "\n";
    /*
    p_dog.print_info();
    p_dog.set_dog_name("Coco");
    p_dog.print_info();

    p_dog.set_dog_name("Pumba")->set_dog_breed("Wire fox")->set_dog_age(4);
    */

    p_dog.set_dog_name("pumba").set_dog_breed("Wire fox").set_dog_age(4);
    p_dog.print_info();
    return 0;
}