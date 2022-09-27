#include "person.h"
using namespace std;
Person::Person()
{
}

Person::Person(string_view m_full_name_param, string_view m_address_param, int m_age_param)
{
    m_full_name = m_full_name_param;
    m_address = m_address_param;
    m_age = m_age_param;
}

std::ostream &operator<<(std::ostream &out, const Person &person)
{
    out << "Person [" << person.m_full_name << " " << person.m_address << " " << person.m_age << "]";
    return out;
}

Person::~Person()
{
}
