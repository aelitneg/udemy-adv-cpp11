#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Primitives
    int x{1};
    cout << x << endl;

    // Strings
    string a{"Guten Morgen!"};
    cout << a << endl;

    // Pointers
    int *p{}; // int *p = nullptr
    cout << p << endl;

    // Default values
    int v[3]{};
    cout << v[1] << endl;

    // Structs
    struct
    {
        int id;
        string name;
    } s{1000, "Andrew"};
    cout << s.id << ' ' << s.name << endl;

    // STL
    vector<int> vec{1, 2, 3, 4, 5};
    cout << vec[2] << endl;
}