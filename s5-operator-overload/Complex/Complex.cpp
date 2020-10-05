#include "./Complex.h"

namespace tutorial
{
    ostream &operator<<(ostream &out, const Complex &c)
    {
        cout << '(' << c.getReal() << "," << c.getImaginary() << ')';
        return out;
    }
    Complex::Complex() {}

    Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

    Complex::Complex(const Complex &other)
    {
        real = other.real;
        imaginary = other.imaginary;
    }

    const Complex &Complex::operator=(const Complex &other)
    {
        real = other.real;
        imaginary = other.imaginary;

        return *this;
    }

    bool Complex::operator==(const Complex &other)
    {
        return real == other.real && imaginary == other.imaginary;
    }

    bool Complex::operator!=(const Complex &other)
    {
        return !(*this == other);
    }

    Complex operator+(const Complex &a, const Complex &b)
    {
        return Complex((a.getReal() + b.getReal()), (a.getImaginary() + b.getImaginary()));
    }

    Complex operator+(const Complex &a, double b)
    {
        return Complex((a.getReal() + b), a.getImaginary());
    }

    Complex operator+(double a, const Complex &b)
    {
        return Complex((a + b.getReal()), b.getImaginary());
    }

    Complex operator!(const Complex &other)
    {
        return Complex(-other.getReal(), -other.getImaginary());
    }

} // namespace tutorial