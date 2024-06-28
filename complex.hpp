#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

class Complex {
public:
    double real;
    double imag;

    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Comparison operators
    bool operator<(const Complex& other) const {
        // Compare based on some criteria, for example, magnitude or real part
        return (real < other.real) || ((real == other.real) && (imag < other.imag));
    }



    // Overload the << operator for easy output
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }
};

#endif // COMPLEX_HPP
