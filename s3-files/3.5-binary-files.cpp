#include <exception>
#include <fstream>
#include <iostream>

#include "FileException.h"

using namespace std;

#pragma pack(push, 1)

struct Session
{
    char name[64];
    int bpm;
    int bitDepth;
    int sampleRate;
};

#pragma pack(pop)

int main()
{
    string filename = "3.5-binary.bin";

    // Write to binary file
    try
    {
        Session session = {"Everybody Wants to Rule the World", 112, 24, 44100};

        ofstream outFile;
        outFile.open(filename, ios::binary);

        if (!outFile)
        {
            throw FileException("Unable to write to file: " + filename);
        }

        outFile.write(reinterpret_cast<char *>(&session), sizeof(Session));

        outFile.close();
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
        return 1;
    }

    // Read from binary file
    try
    {
        Session session = {};

        ifstream inFile;
        inFile.open(filename, ios::binary);

        if (!inFile)
        {
            throw FileException("Unable to read from file: " + filename);
        }

        inFile.read(reinterpret_cast<char *>(&session), sizeof(Session));

        inFile.close();

        cout << "Name: " << session.name << endl;
        cout << "BPM: " << session.bpm << endl;
        cout << "Bit Depth: " << session.bitDepth << endl;
        cout << "Sample Rate: " << session.sampleRate << endl;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
        return 1;
    }
}