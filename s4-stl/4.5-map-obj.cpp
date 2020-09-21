#include <iostream>
#include <map>

using namespace std;

class Person
{
public:
    Person() : name(""), age(0)
    {
        // Default Constructor
    }

    Person(string name, int age) : name(name), age(age)
    {
        // Constructor with Initializers
    }

    Person(const Person &other)
    {
        // Copy Constructor
        cout << "Copy Constructor " << other.name << " " << other.age << endl;
        name = other.name;
        age = other.age;
    }

    void Print()
    {
        cout << name << " " << age << endl;
    }

private:
    string name;
    int age;
};

int main()
{
    map<int, Person> people;

    people[0] = Person("Andrew", 30);
    people.insert(make_pair(10, Person("Laine", 26)));

    for (map<int, Person>::iterator it = people.begin(); it != people.end(); it++)
    {
        it->second.Print();
    }
    return 0;
}