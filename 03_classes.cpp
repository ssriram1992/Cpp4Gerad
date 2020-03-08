#include <cmath>
#include <iostream>

class Complex {
private:
  double real{0};
  double imag{0};
  const double pi{3.14159}; // Not a constant?

public:
  // Complex(const double real = 0, const double imag = 0) {
  //   std:: cout << "Haha! My first constructor in c++ \n";
  //   this->real = real;
  //   this->imag = imag;
  // }
  Complex (const bool phase = true,const  double mag, const double phase){
    real = mag * std::cos(phase);
    imag = mag * std::sin(phase);
  }
  // // Alternate
  // Complex(double real=0, double imag=0){
  // this->real=real;
  // this->imag=imag;
  // }
  // Alternate - Best choice
  Complex(double real = 0, double imag = 0) : real{real}, imag{imag} {
    // Nothing here
  }

  // Absolute value and phases
  void conjugateIt(){
    imag = -imag;
  }
  double realPart() const { return real; }
  double imagPart() const { return imag; }
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
