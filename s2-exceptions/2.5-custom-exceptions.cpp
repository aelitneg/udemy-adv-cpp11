#include <iostream>
#include <exception>

using namespace std;

class CustomException: public exception {
public: 
    virtual const char* what() const throw() {
        return "Something bad happened";
    }
};

class Test {
public:
    void badFunction() {
        throw CustomException();
    }
};

int main() {
    Test test;

    try {
        test.badFunction();
    } catch (CustomException &e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "Still running..." << endl;
    return 0;
}