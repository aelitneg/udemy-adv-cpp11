#include <fstream>
#include <iostream>
#include <list>

#include "FileException.h"

using namespace std;

struct Song
{
    char name[64];
    char artist[64];
};

fstream *OpenFile(string filename, ios::openmode open_mode)
{
    fstream *file = new fstream();

    file->open(filename, open_mode);
    if (!file->is_open())
    {
        throw FileException("Unable to open file: " + filename);
    }

    return file;
}

void LoadLibrary(list<Song> *lib, string filename)
{
    fstream *file = OpenFile(filename, ios::in | ios::binary);

    while (file->peek() != EOF)
    {
        Song song = {};
        file->read(reinterpret_cast<char *>(&song), sizeof(Song));
        lib->push_back(song);
    }

    file->close();
}

void SaveLibrary(list<Song> *lib, string filename)
{
    fstream *file = OpenFile(filename, ios::out | ios::binary);

    for (list<Song>::iterator it = lib->begin(); it != lib->end(); it++)
    {
        file->write(reinterpret_cast<char *>(&*it), sizeof(Song));
    }

    file->close();
}

void PrintLibrary(list<Song> *lib)
{
    int i = 1;

    cout << endl;

    for (list<Song>::iterator it = lib->begin(); it != lib->end(); it++)
    {
        string name = it->name;
        string artist = it->artist;
        cout << "Loaded Song: [" << i << "] " << name << " - " << artist << endl;
        i++;
    }

    cout << endl;
}

void CopyCharArray(char *a, char *b)
{
    for (int i = 0; i < 64; i++)
    {
        b[i] = a[i];
    }
}

void AddSong(list<Song> *lib)
{
    char name[64];
    char artist[64];

    cin.ignore();

    cout << "Enter Name: ";
    cin.getline(name, sizeof(name));

    cout << "Enter Artist: ";
    cin.getline(artist, sizeof(artist));

    Song *song = new Song();
    CopyCharArray(name, song->name);
    CopyCharArray(artist, song->artist);

    lib->push_back(*song);
}

void RemoveSong(list<Song> *lib, int index)
{
    int i = 1;
    for (list<Song>::iterator it = lib->begin(); it != lib->end(); it++)
    {
        if (index == i)
        {
            lib->erase(it);
            return;
        }
        i++;
    }
}

int Menu()
{
    int op;
    cout << endl;
    cout << "Choose an option: " << endl;
    cout << "[1] Print Library" << endl;
    cout << "[2] Add Song" << endl;
    cout << "[3] Remove Song" << endl;
    cout << "[0] Exit" << endl;

    cout << "Please make a selection: ";
    cin >> op;

    cout << endl;
    return op;
}

int main()
{
    try
    {
        cout << "C++ Music Library" << endl;

        string filename = "library.bin";
        list<Song> library;

        LoadLibrary(&library, filename);
        PrintLibrary(&library);

        int op = Menu();
        while (op)
        {
            switch (op)
            {
            case 1:
                PrintLibrary(&library);
                break;
            case 2:
                AddSong(&library);
                break;
            case 3:
                int id;
                cout << "Enter ID to remove: ";
                cin >> id;
                if (!id)
                {
                    break;
                }
                RemoveSong(&library, id);
                break;
            case 0:
                break;
            }
            op = Menu();
        }

        SaveLibrary(&library, filename);

        return 0;
    }
    catch (exception &e)
    {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
}