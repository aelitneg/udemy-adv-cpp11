#include <iostream>
#include <functional>

using namespace std;

auto lambda = [](int a, int b) -> int { return a * b; };

int func(int a, int b)
{
    return a * b;
}

class Functor
{
public:
    int operator()(int a, int b)
    {
        return a * b;
    }
} functor;

void test(int a, int b, function<int(int, int)> fn)
{
    cout << "test: " << fn(a, b) << endl;
}

int main()
{

    test(2, 2, lambda);
    test(2, 3, func);
    test(3, 4, functor);

    return 0;
}