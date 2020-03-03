#include <cmath>
#include <iostream>

class Complex {
private:
  double real{0};
  double imag{0};
  double pi{3.14159}; // Not a constant?

public:
  Complex(double r = 0, double i = 0) {
    real = r;
    imag = i;
  }
  // // Alternate
  // Complex(double real=0, double imag=0){
  // this->real=real;
  // this->imag=imag;
  // }
  // Alternate - Best choice
  // Complex(double real = 0, double imag = 0) : real{real}, imag{imag} {}

  // Absolute value and phases
  double realPart() { return this->real; }
  double imagPart() { return this->imag; }
  double abs() { return std::sqrt(real * real + imag * imag); }
  double phase() {
    if (real == 0 && imag == 0)
      return 0;
    if (real == 0)
      return pi / 2;
    return std::atan(imag / real);
  }
  double phaseAsPiFactor() {
    if (real == 0 && imag == 0)
      return 0;
    if (real == 0)
      return 1.0 / 2;
    return std::atan(imag / real) / pi;
  }
};

// std::ostream &operator<<(std::ostream &out, Complex z) {
// return out << z.realPart() << "+" << z.imagPart() << "i";
// }

// Write routines to add/multiply two complex numbers.

int main() {
  Complex z{1.732, 3};
  // std::cout << "The complex number is " << z << '\n';
  std::cout << "Real part: " << z.realPart() << '\n';
  std::cout << "Imaginary part: " << z.imagPart() << '\n';
  std::cout << "Absolute value: " << z.abs() << '\n';
  // std::cout << "Phase value: "<<z.phase()<<'\n';
  std::cout << "Phase value: " << z.phase() << " = " << z.phaseAsPiFactor()
            << "pi" << '\n';
  return 0;
}

/*
 * TO DISCUSS: What are the proiblems with this code?
 *
 * 1. No constant specifiers.
 * 2. What if abs() and phase() were expensive operations?
 */
