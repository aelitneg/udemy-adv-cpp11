#include <iostream>

using namespace std;

class Audio
{
public:
    Audio() {}

    void play()
    {
        cout << "playing audio" << endl;
    }
};

Audio createAudio()
{
    return Audio();
}

void playAudio(Audio &&audio)
{
    audio.play();
}

int main()
{
    Audio audio = Audio();

    playAudio(static_cast<Audio &&>(audio));

    return 0;
}