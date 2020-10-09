#include <iostream>

using namespace std;

class Test
{
public:
    virtual bool operator()(float a) = 0;
};

class Silence : public Test
{
public:
    bool operator()(float a)
    {
        return a == 0.0;
    }
};

class Clipping : public Test
{
public:
    bool operator()(float a)
    {
        return a == 1.0;
    }
};

void check(float a, Test &test)
{
    if (test(a))
    {
        cout << "pass" << endl;
    }
    else
    {
        cout << "fail" << endl;
    }
}

int main()
{
    Silence tSilence;
    Clipping tClipping;

    check(1.0, tSilence);
    check(1.0, tClipping);
    check(0.0, tSilence);
    check(0.0, tClipping);
    check(0.5, tSilence);
    check(0.5, tClipping);
}