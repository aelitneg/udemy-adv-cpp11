#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int length;

    cout << "Enter Length: ";
    cin >> length;

    vector<vector<int>> table(length, vector<int>(length));

    for (int row = 0; row < table.size(); row++)
    {
        for (int col = 0; col < table[row].size(); col++)
        {
            cout << (row + 1) * (col + 1) << " " << flush;
        }

        cout << endl;
    }
    return 0;
}