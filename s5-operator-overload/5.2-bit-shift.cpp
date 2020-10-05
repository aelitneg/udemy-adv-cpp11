#include <iostream>

using namespace std;

class User
{
public:
    User() : id(0), name("") {}

    User(string name) : name(name)
    {
        id = nextId++;
    }

    User(const User &other)
    {
        id = nextId++;
        name = other.name;
    }

    friend ostream &operator<<(ostream &out, const User user)
    {
        out << user.id << ": " << user.name;
        return out;
    }

private:
    int id;
    string name;

    static int nextId;
};

int User::nextId = 1000;

int main()
{
    User user("Andrew");
    cout << user << endl;
    return 0;
}