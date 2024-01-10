// P03ComplexNumbersDriver
//
// SAMPLE TEST SUITE structure. YOU MUST COMPLETE MANY MORE TESTS
// Test Suite for complex number class
// Written: Stefanos Charalampous
// Date: Fall 2023

#include <iostream>
#include "complex.h"
#include <cmath>
#include <assert.h>
using namespace std;

complex f(const complex& z) {
	return z * z * z - 3 * z * z + 4 * z - 2;
}

inline bool approx_value(double x, double y) {
	return (y - .0001 <= x && x <= y + .0001);
}

bool assertx(bool expr, unsigned line) {
	if (!expr) cerr << "Error at line " << line << endl; return expr;
}

int main()
{
	const double PI = 3.141592653589793;
	const complex i(0, 1);
	complex z1, z2, z3;
	complex z4 = complex(1, 2);
	complex complex_number[] = { complex(2,3),  complex(-1,1), complex(1,1),
							  complex(1,-1), complex(1,0) };
	complex sum = 0.0;
	double x1;
	double y1;
	complex z8;
	double r_z8;
	double arg_z8;

	complex z5;
	cout << "\nTesting >>: input a complex number (3, -2): ";
	cin >> z5;
	assertx(z5.real() == 3.0, __LINE__);
	assertx(z5.imag() == -2.0, __LINE__);

	cout << "\nTesting <<: output a complex number(3, -2): " << z5;

	cout << "\n\nTesting Assignment Operator";
	z1 = complex(3, 2);
	z2 = complex(-4, 3);
	z4 = z3;

	cout << "\n\nTesting Complex Math Operators with Object";
	z3 += z2;
	assertx(z3 == z2, __LINE__);
	z3 -= z2;
	assertx(z4 == z3, __LINE__);
	z3 *= z2;
	z3 /= z2;
	assertx(z3 == z4, __LINE__);

	cout << "\n\nTesting Complex Math Operators with Constants";
	x1 = z3.real();
	y1 = z3.imag();
	const double C = 3.0;
	z3 += C;
	assertx((z3.real() == (x1 + C)) && (z3.imag() == y1), __LINE__);
	z3 -= C;
	assertx((z3.real() == x1) && (z3.imag() == y1), __LINE__);
	z3 *= C;
	assertx((z3.real() == (x1 * C)) && (z3.imag() == (y1 * C)), __LINE__);
	z3 /= C;
	assertx((z3.real() == x1) && (z3.imag() == y1), __LINE__);

	cout << "\n\nTesting Complex Infix Operators with Objects";
	assertx(z1 == complex(3, 2), __LINE__);
	assertx(z2 == complex(-4, 3), __LINE__);
	assertx((z1 + z2) == complex(-1, 5), __LINE__);
	assertx((z1 - z2) == complex(7, -1), __LINE__);
	assertx((z1 * z2) == complex(-18, 1), __LINE__);
	assertx((z1 / z2) == complex(-0.24, -0.68), __LINE__);

	cout << "\n\nTesting Polar Magnitude Calculation";
	z1 = complex(2, 3);
	assertx(z1.real() == 2.0, __LINE__);
	assertx(z1.imag() == 3.0, __LINE__);
	assertx(real(z1) == 2.0, __LINE__);
	assertx(imag(z1) == 3.0, __LINE__);
	assertx(z1.magnitude() == sqrt(z1.real() * z1.real() + z1.imag() * z1.imag()), __LINE__);

	cout << "\n\nTesting Polar Arg Calculation";
	assertx(arg(complex(1., 0.)) == 0.0, __LINE__);
	assertx(approx_value(arg(complex(0, 1)), PI / 2.0), __LINE__);
	assertx(approx_value(arg(complex(-1, 0)), PI), __LINE__);

	cout << "\n\nTesting Coordinate to Polar";
	z8 = complex{ .5, 4.0 };
	r_z8 = magnitude(z8);
	arg_z8 = arg(complex(z8));
	assertx(approx_value(polar(r_z8, arg_z8).real(), .5), __LINE__);
	assertx(approx_value(polar(r_z8, arg_z8).imag(), 4.0), __LINE__);

	z8 = complex{ -3.0, 7.0 };
	r_z8 = magnitude(z8);
	arg_z8 = arg(complex(z8));
	assertx(approx_value(polar(r_z8, arg_z8).real(), -3.0), __LINE__);
	assertx(approx_value(polar(7.61577, 1.97569).imag(), 7.0), __LINE__);

	cout << "\n\nTesting Chained Calculations";
	assertx(f(complex_number[0]) == complex(-25, -15), __LINE__);
	assertx(f(complex_number[1]) == complex(-4, 12), __LINE__);
	assertx(f(complex_number[2]) == complex(0, 0), __LINE__);
	assertx(f(complex_number[3]) == complex(0, 0), __LINE__);
	assertx(f(complex_number[4]) == complex(0, 0), __LINE__);

	// ************************* STUDENTS SHOULD ADD AT LEAST 10 ADDITIONAL TESTS HERE **************************

	cout << "\n\nTesting conjugate of a complex number ";
	complex z01{ 3, -4 };

	assertx(conj(z01) == complex(3, 4), __LINE__);

	cout << "\n\nTesting division of a complex number by a complex number ";
	complex z02 = complex{ 12, 8 };
	complex z03 = complex{ 4, 2 };

	assertx(z02 / z03 == complex(3.2, 0.4), __LINE__);

	cout << "\n\nTesting real part of a complex number ";
	complex z04{ 6, -7 };
	assertx(real(z04) == 6.0, __LINE__);

	cout << "\n\nTesting imaginary part of a complex number ";

	assertx(imag(z04) == -7.0, __LINE__);

	cout << "\n\nTesting multiplication of a complex number with a complex number ";
	complex z05 = complex(3, 2);
	complex z06 = complex(2, 1);

	assertx(z05* z06 == complex(4, 7), __LINE__);

	cout << "\n\nTesting magnitude of a complex number ";
	complex z07(3, 4);
	assertx(approx_value(magnitude(z07), 5.0), __LINE__);

	cout << "\n\nTesting equality of two complex numbers (equal) ";
	complex z08{ 2, 3 };
	complex z09{ 2, 3 };

	assertx(z08 == z09, __LINE__);

	cout << "\n\nTesting complex number division by a double ";
	complex z10(4, 6);
	double z10_double = 2.0;

	assertx(z10 / z10_double == complex(2, 3), __LINE__);

	cout << "\n\nTesting equality of two complex numbers (not equal): ";
	complex z11(2, 3);
	complex z12(4, 1);

	assertx(z11 != z12, __LINE__);

	cout << "\n\nTesting complex number addition with a double: ";
	complex z13(5, 3);
	double z13_double = 2.5;

	assertx(z13 + z13_double == complex(7.5, 3), __LINE__);

	cout << "\n\nTesting complex number subtraction from a double: ";
	complex z14(4, 2);
	double z14_double = 1.5;

	assertx(z14_double - z14 == complex(-2.5, -2), __LINE__);

	cout << "\n\nTesting complex number multiplication with a double ";
	complex z15(2, 3);
	double z15_double = 2.5;

	assertx(z15 * z15_double == complex(5, 7.5), __LINE__);

	cout << "\n\nPASSED TESTS\n";

	return 0;
}