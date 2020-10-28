#include <iostream>

using namespace std;

class Parent
{
public:
    Parent() : Parent(0)
    {
        cout << "Parent() constructor" << endl;
    }

    Parent(int p) : p(p)
    {
        cout << "Parent(int) constructor" << endl;
    };

private:
    int p;
};

class Child : Parent
{
public:
    Child()
    {
        cout << "Child() constructor" << endl;
    }

    Child(int c) : c(c)
    {
        cout << "Child(int) constructor" << endl;
    }

private:
    int c;
};
int main()
{
    Parent parent;
    Child child;
    return 0;
}