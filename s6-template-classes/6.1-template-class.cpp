#include <iostream>

using namespace std;

class Student
{
public:
    Student(int id, string name) : id(id), name(name) {}

    bool operator<(const Student &other)
    {
        return id < other.id;
    }

    friend ostream &operator<<(ostream &out, const Student s)
    {
        out << s.id << " : " << s.name << flush;
        return out;
    }

private:
    int id;
    string name;
};

template <class T>
class User
{
public:
    User(T user) : user(user) {}

    void print()
    {
        cout << user << endl;
    }

private:
    T user;
};

int main()
{
    User<Student> user1(Student(1000, "Andrew"));

    user1.print();
    return 0;
}