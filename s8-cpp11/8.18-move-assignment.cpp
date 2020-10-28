#include <iostream>
#include <memory.h>

using namespace std;

class AudioEngine
{
private:
    int *_buffer{nullptr};
    const int _kBufferLength{32};

public:
    AudioEngine()
    {
        cout << "AudioEngine()" << endl;
        _buffer = new int[_kBufferLength]{0};
    }

    AudioEngine(AudioEngine &other)
    {
        cout << "AudioEngine(&AudioEngine)" << endl;
        memcpy(_buffer, other._buffer, sizeof(int) * _kBufferLength);
    }

    AudioEngine(AudioEngine &&other)
    {
        cout << "AudioEngine(&&AudioEngine)" << endl;
        _buffer = other._buffer;
        other._buffer = nullptr;
    }

    AudioEngine &operator=(AudioEngine &&other)
    {
        cout << "AudioEngine &operator=" << endl;
        _buffer = new int[_kBufferLength]{0};
        memcpy(_buffer, other._buffer, sizeof(int) * _kBufferLength);

        return *this;
    }

    ~AudioEngine()
    {
        cout << "~AudioEngine()" << endl;
        delete[] _buffer;
    }
};

AudioEngine createAudioEngine()
{
    cout << "createAudioEngine()" << endl;
    return AudioEngine();
}

int main()
{
    AudioEngine audioEngine;
    audioEngine = createAudioEngine();

    return 0;
}