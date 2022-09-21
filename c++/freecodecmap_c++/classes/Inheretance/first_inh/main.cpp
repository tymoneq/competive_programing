#include <bits/stdc++.h>

using namespace std;

class Person
{
    friend ostream &operator<<(ostream &out, const Person &person)
    {
        return out;
    }

public:
    Person();
    Person(string first_name_param, string last_name_param);

    string get_first_name() const
    {
        return first_name;
    }
    string get_last_name() const
    {
        return last_name;
    }

private:
    string first_name = "None";
    string last_name = "None";
};

class Player : public Person
{
    friend ostream &operator<<(ostream &out, const Player &player)
    {
        out << "Player game " << player.m_game << " names: " << player.get_first_name() << " " << player.get_last_name() << "\n";
        return out;
    };

public:
    Player() = default;
    Player(string_view game_param)
    {
        m_game = game_param;
    }

private:
    string_view m_game{"None"};
};

int main()
{
    Player player1("basketball");
    player1.get_first_name();

    return 0;
}