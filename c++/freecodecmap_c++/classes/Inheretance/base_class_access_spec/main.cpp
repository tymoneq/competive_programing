#include <bits/stdc++.h>

#include "player.h"

int main()
{
    Person person1("Daniel JD", "Blue sky", 56);
    cout << person1;

    cout << "\n ---------------------------------------------------"
         << "\n";

    Player player1;
    cout << player1.get_address() << "\n";
    return 0;
}