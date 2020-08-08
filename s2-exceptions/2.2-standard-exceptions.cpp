#include <iostream>

using namespace std;

class AllYourMemory {
    public: AllYourMemory() {
        char *pMemory = new char[17179860387];
        delete[] pMemory;
    }
};

int main() {
    try {
        AllYourMemory allYourMemory;
    } catch (bad_alloc &e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "Still Running..." << endl;
    
    return 0;
}