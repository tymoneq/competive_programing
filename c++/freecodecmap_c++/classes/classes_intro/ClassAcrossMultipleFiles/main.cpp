/**
 * The main function creates an object of the class Cylinder and calls the volume function to calculate
 * the volume of the cylinder
 * 
 * @return The volume of the cylinder.
 */
#include <bits/stdc++.h>

#include "cylinder.h"

using namespace std;

int main()
{
    Cylinder cylinder1;
    cout << "volume c1 : " << cylinder1.volume() << "\n";

    cout << cylinder1.get_base_radius() << "\n";
    cout << cylinder1.get_height() << "\n";
    cylinder1.set_base_radius(5);
    cylinder1.set_height(6);
    cout << "Volume c1 : " << cylinder1.volume() << "\n";

    return 0;
}