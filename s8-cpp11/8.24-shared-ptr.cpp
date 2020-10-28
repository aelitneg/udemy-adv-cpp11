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
};

int main()
{
    shared_ptr<Audio> audio1 = make_shared<Audio>();

    {
        shared_ptr<Audio> audio2 = make_shared<Audio>();
        audio2 = audio1; // Toggle this line
        cout << "Exiting local scope" << endl;
    }

    cout << "Exiting main()" << endl;
    return 0;
}