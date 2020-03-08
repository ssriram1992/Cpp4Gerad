#include <cmath>
#include <iostream>

class Complex {
private:
  double real{0};
  double imag{0};
  static constexpr double pi{3.14159}; 

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
    static unsigned int count {0};
    this->real = real;
    this->imag = imag;
    count++ ;
    std::cout << count;
  }
};

std::ostream &operator<<(std::ostream &out, Complex z) {
  if (z.imagPart() == 0)
    return out << z.realPart();
  if (z.imagPart() > 0)
    return out << z.realPart() << "+" << z.imagPart() << "i";
  else
    return out << z.realPart() << z.imagPart() << "i";
}

// Fix this function so that it works!
// Good place to explain auto/const/static/volatile
void ConjugateIt(Complex &z) {
  auto r = z.realPart();
  auto i = z.imagPart();
  z.reset(r, -i);
  std::cout << "Inside ConjugateIt(): " << z << '\n';
}

int main() {
  Complex z{1.732, 3};
  std::cout << z << '\n';
  z.reset(2, 2);
  std::cout << z << '\n';

  ConjugateIt(z);
  std::cout << "Outside ConjugateIt(): " << z << '\n';
// ./04_classes                                                                                                                                                                                                                                 
// 1.732+3i                                                                                                                                                                                                                                     
// 2+2i                                                                                                                                                                                                                                         
// Inside ConjugateIt(): 2-2i                                                                                                                                                                                                                   
// Outside ConjugateIt(): 2+2i  
  return 0;
}
