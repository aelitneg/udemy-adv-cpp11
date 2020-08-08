#include <iostream>
#include <exception>

using namespace std;

class AudioException: public exception {
public:
    virtual const char* what() const throw() {
        return "AudioException";
    }
};

void play() {
    bool stdError = true;
    bool audioError = true;

    if (audioError) {
        throw AudioException();
    }

    if (stdError) {
        throw exception();
    }
}

int main() {
    try {
        play();
    } catch (AudioException &e) {
        cout << "Cating AudioException: " << e.what() << endl;
    } catch (exception &e) {
        cout << "Catching exception: " << e.what() << endl;
    }
    return 0;
}