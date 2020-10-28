#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;

int processA(int a, int b, int c)
{
    cout << "processA: " << a << ' ' << b << ' ' << c << endl;
    return a + b + c;
}

void processB(function<int(int, int)> func)
{
    cout << "processB: " << func(100, 200) << endl;
}

class Processor
{
public:
    int processC(int a, int b, int c)
    {
        cout << "processC: " << a << ' ' << b << ' ' << c << endl;
        return a + b + c;
    }

    static int processD(int a, int b, int c)
    {
        cout << "processD: " << a << ' ' << b << ' ' << c << endl;
        return a + b + c;
    }
};

int main()
{
    auto callback1 = bind(processA, 1, 2, 3);
    callback1();

    auto callback2 = bind(processA, 10, _1, _2);
    callback2(20, 30);

    auto callback3 = bind(processA, 10, _2, _1);
    callback3(20, 30);

    processB(callback3);

    Processor processor;
    auto callback4 = bind(&Processor::processC, processor, 1000, 2000, 3000);
    callback4();

    auto callback5 = std::bind((int (*)(int, int, int)) & Processor::processD, 1, 2, 3);
    callback5();
    return 0;
}