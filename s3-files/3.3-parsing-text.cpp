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
        string fileName = "3.3-population.txt";

        inFile.open(fileName);

        if (!inFile.is_open())
        {
            throw FileException("Unable to open file: " + fileName);
        }

        while (inFile)
        {
            string country;
            getline(inFile, country, ':');

            int population;
            inFile >> population;

            inFile >> ws;

            if (!inFile)
            {
                break;
            }

            cout << country << " -- " << population << endl;
        }

        inFile.close();
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
