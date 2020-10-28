#include <iostream>

using namespace std;

void test(void (*pFunc)())
{
    pFunc();
}

int main()
{
    auto func = []() { cout << "Hello Lambda" << endl; };

    func();

    test(func);

    test([]() { cout << "Hello Inline Lambda" << endl; });
    return 0;
}