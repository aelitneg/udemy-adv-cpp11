#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, int> ages;

    // Array Syntax
    ages["Mike"] = 40;
    ages["Andrew"] = 30;

    // Pair Constructor
    pair<string, int> person("Laine", 26);
    ages.insert(person);

    // Pair Constructor Shorthand
    ages.insert(pair<string, int>("Peggy", 67));

    // Make Pair Helper Function
    ages.insert(make_pair("Dan", 37));

    for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }

    for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++)
    {
        pair<string, int> age = *it;
        cout << age.first << ": " << age.second << endl;
    }

    if (ages.find("Vixky") != ages.end())
    {
        cout << "Ages contains 'Vicky'" << endl;
    }
    else
    {
        cout << "Ages does not contain 'Vicky'" << endl;
    }
    return 0;
}
