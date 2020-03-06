#include <cmath>
#include <iostream>

#include "complex.h"
using std::cin;
using std::cout;

unsigned int Complex::objCount = 0;

std::ostream &operator<<(std::ostream &out, const Complex &z) {
  out << "(obj " << z.thisCount << ") ";
  if (z.imagPart() == 0)
    return out << z.realPart();
  if (z.imagPart() > 0)
    return out << z.realPart() << "+" << z.imagPart() << "i";
  else
    return out << z.realPart() << z.imagPart() << "i";
}

Complex::Complex(const Complex &c)
    : real{c.real}, imag{c.imag}, thisCount{++this->objCount} {
  cout << "In the copy constructor, copying: " << c << "\n";
}

Complex &Complex::operator=(const Complex &c) {
  real = c.real;
  imag = c.imag;
  cout << "In the copy assignment constructor, copying: " << c << "\n";
  return *this;
}

Complex::Complex(Complex &&c)
    : real{c.real}, imag{c.imag}, thisCount{++this->objCount} {
  cout << "In the move constructor, copying: " << c << "\n";
}

Complex &Complex::operator=(Complex &&c) {
  real = c.real;
  imag = c.imag;
  cout << "In the move assignment constructor, copying: " << c << "\n";
  return *this;
}
Complex::Complex(const double real, const double imag)
    : real{real}, imag{imag}, thisCount{++this->objCount} {
  cout << "In the regular constructor " << real << " " << imag << " "
       << thisCount << "\n";
}
Complex::~Complex() {
  cout << "In the destructor of obj " << thisCount << "\n";
}

double Complex::abs() const { return std::sqrt(real * real + imag * imag); }
double Complex::phase() const {
  if (real == 0 && imag == 0)
    return 0;
  if (real == 0)
    return pi / 2;
  return std::atan(imag / real);
}
double Complex::phaseAsPiFactor() const {
  if (real == 0 && imag == 0)
    return 0;
  if (real == 0)
    return 1.0 / 2;
  return std::atan(imag / real) / pi;
}

void Complex::reset(double real = 0, double imag = 0) {
  this->real = real;
  this->imag = imag;
}
Complex operator*(Complex z1, Complex z2) {
  auto r = z1.realPart() * z2.realPart() - z1.imagPart() * z2.imagPart();
  auto c = z1.realPart() * z2.imagPart() + z1.imagPart() * z2.realPart();
  return Complex{r, c};
}
