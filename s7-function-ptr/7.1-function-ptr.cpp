#include <iostream>

using namespace std;

string greet(string firstName, string lastName)
{
    return "Hello " + firstName + " " + lastName;
}

int main()
{
    cout << "Direct: " << greet("Andrew", "Gentile") << endl;

    string (*pGreet1)(string, string);
    pGreet1 = &greet;
    cout << "Full Syntax: " << (*pGreet1)("Nina", "Simone") << endl;

    string (*pGreet2)(string, string) = greet;
    cout << "Short Syntax: " << pGreet2("Laine", "Matthews") << endl;

    return 0;
}