#include <iostream>
#include <map>

using namespace std;

int main()
{
    multimap<int, string> lookup;

    lookup.insert(make_pair(1000, "Andrew"));
    lookup.insert(make_pair(1001, "Laine"));
    lookup.insert(make_pair(1002, "Nina"));
    lookup.insert(make_pair(1002, "Fred"));

    for (multimap<int, string>::iterator it = lookup.begin(); it != lookup.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }

    cout << endl;

    pair<multimap<int, string>::iterator, multimap<int, string>::iterator> a = lookup.equal_range(1002);
    for (multimap<int, string>::iterator it = a.first; it != a.second; it++)
    {
        cout << it->first << ": " << it->second << endl;
    }

    cout << endl;

    auto b = lookup.equal_range(1002);
    for (multimap<int, string>::iterator it = b.first; it != b.second; it++)
    {
        cout << it->first << ": " << it->second << endl;
    }
    return 0;
}