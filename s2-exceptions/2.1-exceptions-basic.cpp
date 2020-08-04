#include <iostream>

using namespace std;

void mightGoWrong() {
    bool error1 = false;
    bool error2 = true;

    if(error1) {
        // throw 8;
        throw "Something went wrong";
    }

    if(error2) {
        // creates a string object and throws the reference
        throw string("Something else went wrong");
    }
}

void useMightGoWrong() {
    mightGoWrong();
}

int main() {
    try {
        useMightGoWrong();
    } catch(int e) {
        cout << "Error Code: " << e << endl;
    } catch (char const * e) {
        cout << "Error: " << e << endl;
    // Catches the reference of the string object. 
    // Reference to object which is out of scope, but exception 
    // handling will clean this up automagically. 
    } catch(string &e) {
        cout << "Error: " << e << endl;
    }
    
    cout << "Still running..." << endl;
    return 0;
}