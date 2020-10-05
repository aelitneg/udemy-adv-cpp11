#include <iostream>
#include "./Complex/Complex.h"

using namespace std;
using namespace tutorial;

int main()
{
    cout << "Overload Left Bitwise" << endl;
    Complex c1(2, 3);
    cout << c1 << endl;

    Complex c2 = c1;
    cout << c1 << " " << c2 << endl;

    c1 = c2;
    cout << c1 << " " << c2 << endl;

    cout << endl;
    cout << "Overload +" << endl;

    cout << c1 + c2 << endl;
    cout << c1 + 5 << endl;
    cout << 10 + c1 << endl;

    cout << endl;
    cout << "Overload ==" << endl;
    cout << c1 << ' ' << c2 << " == " << ((c1 == c2) ? "true" : "false") << endl;

    Complex c3(1, 2);
    cout << c1 << ' ' << c3 << " != " << ((c1 != c3) ? "true" : "false") << endl;

    cout << endl;
    cout << "Overload !" << endl;
    cout << !c3 << endl;
    return 0;
}