#include <exception>
#include <iostream>

using namespace std;

class FileException: public exception {
public: 
    FileException(string errMsg) {
        this->errMsg.append(errMsg);
    }

    virtual const char* what() const throw() {
        return this->errMsg.c_str();
    }
private: 
    string errMsg = "FileException: ";
};