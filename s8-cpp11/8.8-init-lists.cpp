#include <iostream>
#include <initializer_list>

using namespace std;

class Test
{
public:
    Test(initializer_list<string> values)
    {
        for (auto value : values)
        {
            cout << value << endl;
        }
    }

    void print(initializer_list<int> values)
    {
        for (auto value : values)
        {
            cout << value << endl;
        }
    }
};

int main()
{
    Test t{"one", "two", "three"};

    t.print({1, 2, 3});
    return 0;
}