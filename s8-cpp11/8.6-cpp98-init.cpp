#include <iostream>

using namespace std;

int main()
{
    int arry[] = {1000, 1001, 1002};
    cout << arry[1] << endl;

    class C
    {
    public:
        int id;
        string name;
    };

    C c1 = {1001, "Andrew"};
    cout << c1.name << endl;

    struct S
    {
        int id;
        string name;
    } s2 = {1003, "Laine"};

    S s1 = {1002, "Nina"};

    cout << s1.name << endl;
    cout << s2.name << endl;
}