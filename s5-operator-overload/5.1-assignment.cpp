#include <iostream>

using namespace std;

class User
{
public:
    // Default Constructor
    User() : id(0), name("")
    {
        cout << "Default Constructor" << endl;
    }

    // Constructor
    User(string name) : name(name)
    {
        cout << "Constructor" << endl;
        id = nextId++;
    }

    // Copy Constructor
    User(const User &other)
    {
        cout << "Copy Constructor" << endl;
        id = nextId++;
        name = other.name;
    }

    // Operator Overload
    const User &operator=(const User &other)
    {
        cout << "Operator Overload" << endl;
        id = nextId++;
        name = other.name;

        return *this;
    }

    void print()
    {
        cout << id << ": " << name << flush;
    }

    static int nextId;

private:
    int id;
    string name;
};

int User::nextId = 1000;

int main()
{
    cout << "Create User 1" << endl;
    User user1("Andrew"); // Constructor

    cout << "Create User 2" << endl;
    User user2(user1); // Copy Constructor

    cout << "create User 3" << endl;
    User user3;
    user3 = user2;

    user1.print();
    cout << endl;

    user2.print();
    cout << endl;

    user3.print();
    cout << endl;

    return 0;
}