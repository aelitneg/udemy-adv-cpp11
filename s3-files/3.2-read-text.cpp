#include <exception>
#include <fstream>
#include <iostream>

#include "FileException.h"

using namespace std;

int main()
{
    try
    {
        ifstream inFile;
        string fileName = "3.1-write.txt";

        inFile.open(fileName);

        if (!inFile.is_open())
        {
            throw FileException("Unable to open file: " + fileName);
        }

        while (inFile)
        {
            string line;
            getline(inFile, line);

            cout << line << endl;
        }
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
}
