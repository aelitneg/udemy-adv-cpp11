#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Song
{
public:
    Song(string name, int bpm) : name(name), bpm(bpm) {}

    bool operator<(const Song &other) const
    {
        return name < other.name;
    }

    void print()
    {
        cout << name << ": " << bpm << flush;
    }

    friend bool compareTempo(const Song &a, const Song &b);

private:
    string name;
    int bpm;
};

bool compareTempo(const Song &a, const Song &b)
{
    return a.bpm < b.bpm;
}
int main()
{
    vector<Song> songs;

    songs.push_back(Song("So What", 100));
    songs.push_back(Song("Maiden Voyage", 95));
    songs.push_back(Song("Impressions", 110));

    cout << "Original" << endl;
    for (vector<Song>::iterator it = songs.begin(); it != songs.end(); it++)
    {
        it->print();
        cout << endl;
    }

    cout << endl;

    sort(songs.begin(), songs.end());
    cout << "Operator Overloaded Sort" << endl;
    for (vector<Song>::iterator it = songs.begin(); it != songs.end(); it++)
    {
        it->print();
        cout << endl;
    }

    cout << endl;

    sort(songs.begin(), songs.end(), compareTempo);
    cout << "Operator Overloaded Sort" << endl;
    for (vector<Song>::iterator it = songs.begin(); it != songs.end(); it++)
    {
        it->print();
        cout << endl;
    }

    return 0;
}