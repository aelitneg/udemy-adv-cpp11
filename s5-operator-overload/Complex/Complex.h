#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
using namespace std;

namespace tutorial
{
    class Complex
    {
    public:
        Complex();
        Complex(double real, double imaginary);
        Complex(const Complex &other);

        const Complex &operator=(const Complex &other);
        bool operator==(const Complex &other);
        bool operator!=(const Complex &other);

        double getReal() const
        {
            return real;
        }

        double getImaginary() const
        {
            return imaginary;
        }

    private:
        double real;
        double imaginary;
    };

    ostream &operator<<(ostream &out, const Complex &c);

    Complex operator+(const Complex &a, const Complex &b);
    Complex operator+(const Complex &a, double b);
    Complex operator+(double a, const Complex &b);

    Complex operator!(const Complex &other);

} // namespace tutorial
#endif // COMPLEX_H_
