#include <cassert>
#include <iostream>
#include <string>

class Debt {
public:
    explicit Debt(std::string internal, std::string external)
        : in { std::move(internal) }
        , ex { std::move(external) }
    {
        assert(in.size() == ex.size());
    }

    void updateIn(size_t pos, char digit)
    {
        in[index(pos)] = digit;
    }

    void updateEx(size_t pos, char digit)
    {
        ex[index(pos)] = digit;
    }

    char get(size_t pos) const
    {
        auto i = index(pos);
        auto result = 0;
        if (i < in.size()) {
            result = digit(in[i]) + digit(ex[i]);
        }
        result += carryFrom(i + 1);
        result -= 10 * (result >= 10);
        return '0' + result;
    }

private:
    size_t index(size_t pos) const
    {
        return in.size() - pos;
    }

    bool carryFrom(size_t index) const
    {
        if (index < in.size()) {
            auto result = digit(in[index]) + digit(ex[index]);
            return result >= 10 || (result == 9 && carryFrom(index + 1));
        }
        return false;
    }

    static int digit(char ch)
    {
        return ch - '0';
    }

private:
    std::string in;
    std::string ex;
};

void setupIO()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

void processData(std::istream& in, std::ostream& out)
{
    size_t n, z;
    std::string internal, external;
    if (in >> n >> z >> internal >> external) {
        Debt debt { std::move(internal), std::move(external) };
        while (z--) {
            char operation;
            size_t i;
            in >> operation >> i;
            if (operation == 'S') {
                out << debt.get(i) << '\n';
            } else {
                char digit;
                in >> digit;
                if (operation == 'W') {
                    debt.updateIn(i, digit);
                } else if (operation == 'Z') {
                    debt.updateEx(i, digit);
                }
            }
        }
    }
}

int main()
{
    setupIO();
    processData(std::cin, std::cout);
    return 0;
}