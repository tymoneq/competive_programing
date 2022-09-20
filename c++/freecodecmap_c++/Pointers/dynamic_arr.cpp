#include <bits/stdc++.h>

using namespace std;

int main()
{
    size_t size{10};

    double *p_saleries{new double[size]};
    int *p_students{new (nothrow) int[size]{}};
    double *p_scores{new (nothrow) double[size]{1, 2, 3, 4, 5}};

    if (p_scores)
    {
        cout << "size of scores : " << sizeof(p_scores) << endl;

        for (size_t i{}; i < size; i++)
        {
            cout << "Value : " << p_scores[i] << " : " << *(p_scores + i) << endl;
        }
    }
    delete[] p_saleries;
    p_saleries = nullptr;

    delete[] p_students;
    p_students = nullptr;

    delete[] p_scores;
    p_scores = nullptr;
    return 0;
}