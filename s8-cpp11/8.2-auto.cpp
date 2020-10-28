#include <iostream>

using namespace std;

// auto as fn return type with inferrence
auto add(int a, int b)
{
    return a + b;
}

// Trailing return types can have expressions
template <class T, class S>
auto concat(T a, S b) -> decltype(a + b)
{
    return a + b;
}

int f()
{
    return 1000;
}

// Trailing return types can also be functions
auto fn() -> decltype(f())
{
    return f();
}

int main()
{
    cout << "add: " << add(2, 2) << endl;
    cout << "concat: " << concat(2, 2) << endl;
    cout << "concat: " << concat(string("Hello "), string("World")) << endl;
    cout << "fn: " << fn() << endl;

    return 0;
}