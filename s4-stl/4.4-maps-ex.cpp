#include <iostream>
#include <map>

using namespace std;

void AddResident(map<string, int> *residents)
{
    string name;
    int apt;

    cout << "Enter name:";
    cin >> name;

    cin.clear();

    cout << "Enter apt:";
    cin >> apt;

    residents->insert(make_pair(name, apt));
}

void DisplayResidents(map<string, int> *residents)
{
    for (map<string, int>::iterator it = residents->begin(); it != residents->end(); it++)
    {
        pair<string, int> res = *it;

        cout << res.first << ": " << res.second << endl;
    }
}

void ResidentSearch(map<string, int> *residents)
{
    string name;
    cout << "Enter name:";
    cin >> name;

    map<string, int>::iterator res = residents->find(name);
    if (res != residents->end())
    {
        cout << res->first << ": " << res->second << endl;
    }
    else
    {
        cout << "Resident not found" << endl;
    }
}

int main()
{
    map<string, int> residents;

    cout << "Residents" << endl;

    cout << "Enter Option:";
    int op;

    cin >> op;
    while (op != 0)
    {
        switch (op)
        {
        case 1:
            DisplayResidents(&residents);
            break;
        case 2:
            AddResident(&residents);
            break;
        case 3:
            ResidentSearch(&residents);
            break;
        }
        cout << "Enter Option:";
        cin >> op;
    }

    return 0;
}