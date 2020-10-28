#include <iostream>

using namespace std;

class Audio
{
public:
    virtual void play()
    {
        cout << "playing audio" << endl;
    }
};

class MP3 : Audio
{
public:
    void play()
    {
        cout << "playing MP3" << endl;
    }
};

int main()
{
    Audio audio;
    MP3 mp3;

    Audio *pAudio = &audio;
    MP3 *pMp3 = &mp3;

    MP3 *p = dynamic_cast<MP3 *>(pAudio);

    if (p == nullptr)
    {
        cout << "invalid cast!" << endl;
    }
    else
    {
        p->play();
    }

    return 0;
}