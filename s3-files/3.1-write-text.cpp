#include <exception>
#include <fstream>
#include <iostream>

#include "FileException.h"

using namespace std;

int main() {
    try {
        ofstream outFile;
        string fileName = "3.1-write.txt";

        string content[6] = {
            "Is this the real life",
            "Is this just fantasy",
            "Caught in a landslide", 
            "No escape from reality",
            "Open your eyes",
            "Look up to the sky and see..."
        };

        outFile.open(fileName);

        // outFile.close();

        if(!outFile.is_open()) {
            throw FileException("Unable to open file: " + fileName);
        }

        for (int i = 0; i < 6; i++) {
            outFile << i+1 << ". " <<  content[i] << endl;
        }
        outFile.close();

    } catch (exception &e) {
        cout << e.what() << endl;
    }
}