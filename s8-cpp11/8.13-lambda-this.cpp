#include <iostream>

using namespace std;

class Test
{
private:
    int one{1};
    int two{2};

public:
    void run()
    {
        int three{3};
        int four{4};

        auto pLambda = [this, three, four]() {
            one = 100;
            cout << "one: " << one << endl;
            cout << "two: " << two << endl;
            cout << "three: " << three << endl;
            cout << "four: " << four << endl;
        };
        pLambda();
    }
};

int main()
{
    Test test;
    test.run();

    return 0;
}