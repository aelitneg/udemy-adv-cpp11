#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Ring
{
public:
    Ring(int size) : _size(size) {}
    int size()
    {
        return _size;
    }

    void add(T value)
    {
        if (_pos >= _size)
        {
            _pos = 0;
        }

        _ring.insert(_ring.begin() + _pos, value);

        _pos++;
    }

    T get(int i)
    {
        return _ring.at(i);
    }

private:
    int _pos = 0;
    int _size;
    vector<T> _ring;
};

int main()
{
    Ring<string> textring(3);
    textring.add("one");
    textring.add("two");
    textring.add("three");
    textring.add("four");
    textring.add("five");

    for (int i = 0; i < textring.size(); i++)
    {
        cout << textring.get(i) << endl;
    }

    Ring<int> numring(3);
    numring.add(1);
    numring.add(2);
    numring.add(3);
    numring.add(4);
    numring.add(5);

    for (int i = 0; i < numring.size(); i++)
    {
        cout << numring.get(i) << endl;
    }

    return 0;
}