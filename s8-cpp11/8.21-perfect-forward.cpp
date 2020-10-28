#include <iostream>

using namespace std;

class Test
{
};

template <class T>
void call(T &&t)
{
    check(t);

    check(static_cast<T &&>(t));

    check(forward<T>(t));
}

void check(Test &t)
{
    cout << "check(&Test)" << endl;
}

void check(Test &&t)
{
    cout << "check&&Test)" << endl;
}

int main()
{
    call<Test>(Test());

    return 0;
}