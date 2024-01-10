#include "Complex.h"
#include <cmath>
using namespace std;

complex::complex() : re(0.0), im(0.0) {}
complex::complex(double a) : re(a), im(0.0) {}
complex::complex(double a, double b) : re(a), im(b) {}
complex::complex(const complex& c) : re(c.re), im(c.im) {}

complex& complex::operator=(const complex& rhs) {
    if (this != &rhs) {
        re = rhs.re;
        im = rhs.im;
    }
    return *this;
}

complex& complex::operator+=(const complex& z) {
    re += z.re;
    im += z.im;
    return *this;
}

complex& complex::operator-=(const complex& z) {
    re -= z.re;
    im -= z.im;
    return *this;
}

complex& complex::operator*=(const complex& z) {
    double temp_re = re * z.re - im * z.im;
    im = re * z.im + im * z.re;
    re = temp_re;
    return *this;
}

complex& complex::operator/=(const complex& z) {
    double denominator = z.re * z.re + z.im * z.im;
    double temp_re = (re * z.re + im * z.im) / denominator;
    im = (im * z.re - re * z.im) / denominator;
    re = temp_re;
    return *this;
}

complex& complex::operator+=(const double x) {
    re += x;
    return *this;
}

complex& complex::operator-=(const double x) {
    re -= x;
    return *this;
}

complex& complex::operator*=(const double x) {
    re *= x;
    im *= x;
    return *this;
}

complex& complex::operator/=(const double x) {
    re /= x;
    im /= x;
    return *this;
}

double complex::real() const {
    return re;
}

double complex::imag() const {
    return im;
}

double complex::magnitude() const {
    return sqrt(re * re + im * im);
}

double complex::arg() const {
    return atan2(im, re);
}

complex operator+(const complex& z1, const complex& z2) {
    return complex(z1.real() + z2.real(), z1.imag() + z2.imag());
}

complex operator-(const complex& z1, const complex& z2) {
    return complex(z1.real() - z2.real(), z1.imag() - z2.imag());
}

complex operator*(const complex& z1, const complex& z2) {
    return complex(
        z1.real() * z2.real() - z1.imag() * z2.imag(),
        z1.real() * z2.imag() + z1.imag() * z2.real()
    );
}

complex operator/(const complex& z1, const complex& z2) {
    double denominator = z2.real() * z2.real() + z2.imag() * z2.imag();
    return complex(
        (z1.real() * z2.real() + z1.imag() * z2.imag()) / denominator,
        (z1.imag() * z2.real() - z1.real() * z2.imag()) / denominator
    );
}

complex operator+(const complex& z) {
    return z;
}
complex complex::conj() const {
    return complex(re, -im);
}
complex operator-(const complex& z) {
    return complex(-z.real(), -z.imag());
}

bool operator==(const complex& z1, const complex& z2) {
    return z1.real() == z2.real() && z1.imag() == z2.imag();
}

bool operator!=(const complex& z1, const complex& z2) {
    return !(z1 == z2);
}
istream& operator>>(istream& is, complex& z) {
    char left_paren, comma, right_paren;
    double p, q;
    is >> left_paren >> p >> comma >> q >> right_paren;
    if (left_paren == '(' && comma == ',' && right_paren == ')') {
        z = complex(p, q);
    }
    return is;
}
ostream& operator<<(ostream& os, const complex& z) {
    os << '(' << z.real() << ", " << z.imag() << ')';

    return os;
}

double magnitude(const complex& z) {
    return sqrt(z.real() * z.real() + z.imag() * z.imag());
}

double real(const complex& z) {
    return z.real();
}

double imag(const complex& z) {
    return z.imag();
}

complex polar(double r, double theta) {
    return complex(r * cos(theta), r * sin(theta));
}

complex conj(const complex& z) {
    return complex(z.real(), -z.imag());
}

double norm(const complex& z) {
    return z.real() * z.real() + z.imag() * z.imag();
}

double arg(const complex& z) {
    return atan2(z.imag(), z.real());
}