#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Student
{
public:
    Student() : id(0), name("") {}
    Student(int id, string name) : id(id), name(name) {}

    void print() const
    {
        cout << id << " " << name << flush;
    }

    bool operator<(const Student &other) const
    {
        return id < other.id;
    }

private:
    int id;
    string name;
};

int main()
{
    map<Student, vector<int>> gradebook;

    // Add students
    gradebook[Student(1000, "Andrew")];
    gradebook[Student(1001, "Laine")];
    gradebook[Student(1002, "Nina")];

    cout << "Test 1" << endl;
    for (map<Student, vector<int>>::iterator it = gradebook.begin(); it != gradebook.end(); it++)
    {
        it->second.push_back(100);

        it->first.print();
        cout << " " << flush;
        for (vector<int>::iterator its = it->second.begin(); its != it->second.end(); its++)
        {
            cout << *its;
        }

        cout << endl;
    }
}