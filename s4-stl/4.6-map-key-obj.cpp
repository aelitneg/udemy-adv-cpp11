#include <iostream>
#include <map>

using namespace std;

class Person
{
public:
    Person() : name(""), age(0){};
    Person(string name, int age) : name(name), age(age){};

    void Print() const
    {
        cout << name << " " << age << flush;
    }

    bool operator<(const Person &other) const
    {
        if (name == other.name)
        {
            // This makes keys specific to name and age
            // Without, "Andrew" is updated to 29
            return age < other.age;
        }

        return name < other.name;
    }

private:
    string name;
    int age;
};

int main()
{
    map<Person, int> people;

    people[Person("Andrew", 30)] = 1000;
    people[Person("Andrew", 29)] = 1005;
    people[Person("Laine", 26)] = 1001;

    for (map<Person, int>::iterator it = people.begin(); it != people.end(); it++)
    {
        cout << "Key: " << flush;
        it->first.Print();
        cout << " Value: " << it->second << endl;
    }

    return 0;
}