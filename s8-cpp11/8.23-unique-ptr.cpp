#include <iostream>
#include <memory>

using namespace std;

class Audio
{
public:
    Audio()
    {
        cout << "Audio()" << endl;
    }

    ~Audio()
    {
        cout << "~Audio()" << endl;
    }

    void play()
    {
        cout << "Audio::play()" << endl;
    }
};

class AudioEngine
{
private:
    unique_ptr<Audio[]> _audioData;

public:
    AudioEngine() : _audioData(new Audio[2])
    {
        cout << "AudioEngine()" << endl;
    }
};

int main()
{
    {
        unique_ptr<Audio> audio1(new Audio);
        audio1->play();
    }

    unique_ptr<Audio[]> audioArry(new Audio[2]);
    audioArry[0].play();

    AudioEngine audioEngine;

    cout << "Exiting" << endl;
    return 0;
}