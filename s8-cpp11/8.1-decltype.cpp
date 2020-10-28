#include <iostream>
#include <typeinfo> // Needed for typeid

using namespace std;

int main()
{
    string type;

    // Declares variable with type of existing variable
    decltype(type) value = "Andrew";

    cout << typeid(type).name() << endl;

    cout << value << endl;

    return 0;
}