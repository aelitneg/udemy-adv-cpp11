#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

class Audio
{
private:
    int *_data{nullptr};
    const int _kSize{32};

public:
    Audio()
    {
        cout << "Audio()" << endl;
    }

    Audio(Audio &&other)
    {
        cout << "Audio(&&Audio)" << endl;
        _data = other._data;
        other._data = nullptr;
    }

    ~Audio()
    {
        cout << "~Audio()" << endl;
        delete[] _data;
    }
};

int main()
{
    vector<Audio> clips;
    clips.push_back(Audio());

    return 0;
}