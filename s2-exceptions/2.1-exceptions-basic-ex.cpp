#include <iostream>
#include <math.h>
using namespace std;

int limiter(int value) {
    if(value > 1024) {
        throw -1;
    } else if(value < 0) {
        throw "Value must be greather than 0";
    } else if(value == 0) {
        throw string("No signal");
    }

    return value;
}

int main() {
    int value; 
    try {
        cout << "Enter input value: ";
        cin >> value;

        value = limiter(value);

        cout << "Limiter: " << value << endl;
    } catch(int e) {
        cout << "Error Code: " << e << endl;
    } catch(char const *e) {
        cout << "Error: " << e << endl;
    } catch(string &e) {
        cout << "Error: " << e << endl;
    }

    return 0;
}