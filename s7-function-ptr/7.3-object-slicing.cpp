#include <iostream>

using namespace std;

class Parent
{
public:
    Parent() : a(0)
    {
        cout << "Parent Constructor" << endl;
    }

    Parent(const Parent &other)
    {
        cout << "Parent Copy Constructor" << endl;
        a = other.a;
    }

    virtual void method()
    {
        cout << "Parent Method" << endl;
    }

private:
    int a;
};

class Child : public Parent
{
public:
    Child() : b(0)
    {
        cout << "Child Constructor" << endl;
    }

    void method()
    {
        cout << "Child Method" << endl;
    }

private:
    int b;
};

int main()
{
    Child c1 = Child();
    c1.method(); // Child Method

    Parent &p1 = c1;

    // if Parent virtual void method() => Child Method
    // If Parent void method() => Parent Method
    p1.method();
    
    return 0;
}