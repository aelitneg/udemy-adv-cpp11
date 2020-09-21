#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> primes;

    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);
    primes.push_back(7);
    primes.push_back(11);

    for (vector<int>::iterator it = primes.begin(); it != primes.end(); it++)
    {
        cout << *it << endl;
    }

    return 0;
}