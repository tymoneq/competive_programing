#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;
class Person
{
    friend std::ostream &operator<<(std::ostream &out, const Person &person);

public:
    Person();
    Person(string_view m_full_name_param, string_view m_address_param, int m_age_param);
    ~Person();

    // Getters
    string_view get_name() const
    {
        return m_full_name;
    }

    string_view get_address() const
    {
        return m_address;
    }

    int get_age() const
    {
        return m_age;
    }

public:
    string_view m_full_name = {"None"};

protected:
    int m_age{0};

private:
    string_view m_address{"Mysterious"};
};

#endif // PERSON_H