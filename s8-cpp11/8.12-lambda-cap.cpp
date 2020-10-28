#include <iostream>

using namespace std;

void test(int (*func)())
{
    cout << "test: " << func() << endl;
}

int main()
{
    int a = 1;
    int b = 2;
    int c;

    cout << "Capture by value:" << endl;
    [a, b]() {
        cout << a << ", " << b << endl;
    }();

    [=]() {
        cout << a << ", " << b << endl;
    }();

    cout << endl;

    cout << "Capture by reference: " << endl;
    [&a, &b, &c]() {
        c = a + b;
    }();
    cout << c << endl;

    [&]() {
        c = a + b;
    }();
    cout << c << endl;

    cout << "Capture by value default, reference exceptions" << endl;
    [=, &c]() {
        c = a + b;
    }();
    cout << c << endl;

    cout << "Capture by reference default, value exceptions" << endl;
    [&, c]() {
        a = b + c;
    }();
    cout << a << endl;
    return 0;
}