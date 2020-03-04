#include <cmath>
#include <iostream>

class Complex {
private:
  double real{0};
  double imag{0};
  static constexpr double pi{3.14159}; // Not a constant?

public:
  Complex(const double real = 0, const double imag = 0)
      : real{real}, imag{imag} {}

  // Absolute value and phases
  double realPart() const { return this->real; }
  double imagPart() const { return this->imag; }
  double abs() const { return std::sqrt(real * real + imag * imag); }
  double phase() const {
    if (real == 0 && imag == 0)
      return 0;
    if (real == 0)
      return pi / 2;
    return std::atan(imag / real);
  }
  double phaseAsPiFactor() const {
    if (real == 0 && imag == 0)
      return 0;
    if (real == 0)
      return 1.0 / 2;
    return std::atan(imag / real) / pi;
  }

  void reset(double real = 0, double imag = 0) {
    this->real = real;
    this->imag = imag;
  }
};
