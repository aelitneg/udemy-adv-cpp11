#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //int primes[] = {1, 3, 5, 7, 11};
    // auto primes = {1, 3, 5, 7, 11};

    vector<int> primes;

    primes.push_back(1);
    primes.push_back(3);
    primes.push_back(5);
    primes.push_back(7);
    primes.push_back(11);

    for (auto p : primes)
    {
        cout << p << endl;
    }

    return 0;
}