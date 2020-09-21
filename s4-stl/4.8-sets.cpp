#include <iostream>
#include <set>
#include <stdlib.h>
#include <time.h>

using namespace std;

void generateNums(set<int> *nums)
{
    while (nums->size() < 6)
    {
        nums->insert(rand() % 100 + 1);
    }
}

class Player
{
public:
    Player(string name) : name(name)
    {
        generateNums(&numbers);
    };

    void print() const
    {
        cout << name << ": " << flush;
        for (set<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
        {
            cout << *it << " " << flush;
        }
        cout << endl;
    }

    bool operator<(const Player &other) const
    {
        return name < other.name;
    }

private:
    string name;
    set<int> numbers;
};

int main()
{
    srand(time(NULL));

    set<int> lottoNumbers;
    set<Player> players;

    players.insert(Player("Andrew"));
    players.insert(Player("Laine"));
    players.insert(Player("Nina"));
    players.insert(Player("Andrew")); // This will not be inserted.

    for (set<Player>::iterator it = players.begin(); it != players.end(); it++)
    {
        it->print();
    }

    while (lottoNumbers.size() < 6)
    {
        lottoNumbers.insert(rand() % 100 + 1);
    }

    cout << "Winning Numbers: " << flush;
    for (set<int>::iterator it = lottoNumbers.begin(); it != lottoNumbers.end(); it++)
    {
        cout << *it << " " << flush;
    }
    cout << endl;

    return 0;
}