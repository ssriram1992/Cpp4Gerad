#pragma once
#include <iostream>

class Complex {
private:
  double real{0};
  double imag{0};
  const unsigned int thisCount;
  static unsigned int objCount;
  static constexpr double pi{3.14159};

public:
  // Friends
  friend std::ostream &operator<<(std::ostream &, const Complex &);
  // Constructors and assignments
  Complex(const double real = 0, const double imag = 0);
  ~Complex();
  Complex(const Complex &c);
  Complex &operator=(const Complex &c);
  Complex(Complex &&c);
  Complex &operator=(Complex &&c);
  // Members
  double realPart() const { return this->real; }
  double imagPart() const { return this->imag; }
  double abs() const;
  double phase() const;
  double phaseAsPiFactor() const;
  void reset(double, double);
};
std::ostream &operator<<(std::ostream &out, const Complex &z);
Complex operator*(Complex, Complex);
