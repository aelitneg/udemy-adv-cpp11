#include <iostream>

using namespace std;

void login(string user, void (*greet)(string))
{
    greet(user);
}

void calc(double (*func)(double, double))
{
    cout << func(10.0, 5.0) << endl;
}

int main()
{
    auto greet = [](string name) { cout << "Hello " << name << endl; };

    login("Andrew", greet);

    auto divide = [](double a, double b) -> double {
        if (!b)
        {
            return 0;
        }

        return a / b;
    };

    calc(divide);
    return 0;
}