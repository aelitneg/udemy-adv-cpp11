#include <iostream>
#include "Ring.h"

using namespace std;

int main()
{
    Ring<string> ring(3);

    ring.add("one");
    ring.add("two");
    ring.add("three");
    ring.add("four");

    // c++ 98 Syntax
    for (Ring<string>::iterator it = ring.begin(); it != ring.end(); it++)
    {
        cout << *it << endl;
    }

    cout << endl;

    // C++ 11 Syntax
    for (string value : ring)
    {
        cout << value << endl;
    }

    cout << endl;

    // C++ 11 Syntax with auto
    for (auto value : ring)
    {
        cout << value << endl;
    }

    return 0;
}