#ifndef NURSE_H
#define NURSE_H
#include "person.h"

using namespace std;

class Nurse : protected Person
{
    friend ostream &operator<<(ofstream &, const Nurse &operand);

public:
    Nurse();
    ~Nurse();

    void treat_unmwell_person()
    {
        m_full_name = "John Snow";
        m_age = 23;
    }

private:
    int practice_certificate_id{0};
};

#endif // NURSE_H