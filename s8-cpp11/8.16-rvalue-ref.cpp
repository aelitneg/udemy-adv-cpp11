#include <iostream>
#include <memory.h>

using namespace std;

class Audio
{
private:
    const int _len = 32;
    int *_data{nullptr};

public:
    Audio()
    {
        cout << "Audio()" << endl;
        _data = new int[_len]{0};
    }

    Audio(const Audio &other)
    {
        cout << "Audio(const &Audio)" << endl;
        memcpy(_data, other._data, sizeof(int) * _len);
    }

    ~Audio()
    {
        cout << "~Audio()" << endl;
        delete[] _data;
    }
};

Audio createAudio()
{
    cout << "createAudio()" << endl;
    return Audio();
}

void test(const int &value)
{
    cout << "Lvalue value: " << value << endl;
}

void test(int &&value)
{
    cout << "Rvalue value: " << value << endl;
}

int main()
{
    Audio audio1 = createAudio();

    // RValue Reference with '&&'
    Audio &&audio2 = createAudio();

    int value = 0;

    test(++value); // LValue
    test(value++); // RValue

    return 0;
}