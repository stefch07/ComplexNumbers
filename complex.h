#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class complex {
public:
    complex();
    complex(double a);
    complex(double a, double b);

    complex(const complex& c);

    complex& operator=(const complex& rhs);

    complex& operator+=(const complex& z);
    complex& operator-=(const complex& z);
    complex& operator*=(const complex& z);
    complex& operator/=(const complex& z);

    complex& operator+=(const double x);
    complex& operator-=(const double x);
    complex& operator*=(const double x);
    complex& operator/=(const double x);

    double real() const;
    double imag() const;
    double magnitude() const;
    double arg() const;
    complex conj() const;

private:
    double re, im;
};

complex operator+(const complex& z1, const complex& z2);
complex operator-(const complex& z1, const complex& z2);
complex operator*(const complex& z1, const complex& z2);
complex operator/(const complex& z1, const complex& z2);

complex operator+(const complex& z);
complex operator-(const complex& z);

bool operator==(const complex& z1, const complex& z2);
bool operator!=(const complex& z1, const complex& z2);

std::istream& operator>>(std::istream& is, complex& z);
std::ostream& operator<<(std::ostream& os, const complex& z);

double magnitude(const complex& z);
double real(const complex& z);
double imag(const complex& z);
complex polar(double r, double theta);
complex conj(const complex& z);
double norm(const complex& z);
double arg(const complex& z);

#endif
