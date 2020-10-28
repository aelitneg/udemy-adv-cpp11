#include <iostream>

using namespace std;

class Test
{
    int id{1000};
    string name{"Anonymous"};

public:
    Test() = default;
    Test(int id) : id(id) {}
    Test(Test &other) = delete;

    void print()
    {
        cout << id << ' ' << name << endl;
    }
};

int main()
{
    Test t1;
    t1.print();

    Test t2{1001};
    t2.print();

    // Doesn't work because copy constructor was removed
    // Test t3 = t2;

    return 0;
}