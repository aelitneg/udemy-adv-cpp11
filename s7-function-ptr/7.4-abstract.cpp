#include <iostream>

using namespace std;

class AudioFile
{
public:
    virtual void play() = 0;
    virtual void trim() = 0;
};

class Wav : public AudioFile
{
public:
    void play()
    {
        cout << "Playing Wav" << endl;
    }

    virtual void trim() = 0;
};

class Clip : public Wav
{
public:
    void play()
    {
        cout << "Playing Clip" << endl;
    }

    void trim()
    {
        cout << "Trim Clip" << endl;
    }
};

void start(AudioFile &audioFile)
{
    audioFile.play();
}

int main()
{
    // AudioFile audioFile; play() and trim() are not implemented

    // Wav wav; trim() is not implemented

    Clip clip;
    clip.play();
    clip.trim();

    // Array can hold different types of subclasses
    AudioFile *audioFiles[1];
    audioFiles[0] = &clip;

    audioFiles[0]->play();
    audioFiles[0]->trim();

    // Functions can take different types of subclasses
    start(clip);

    return 0;
}
