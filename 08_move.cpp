#include <cmath>
#include <iostream>

using std::cin;
using std::cout;

class Complex {
private:
  double real{0};
  double imag{0};
  const unsigned int thisCount;
  static unsigned int objCount;
  static constexpr double pi{3.14159};

public:
  friend std::ostream &operator<<(std::ostream &, const Complex &);
  Complex(const double real = 0, const double imag = 0)
      : real{real}, imag{imag}, thisCount{++this->objCount} {
    cout << "In the regular constructor " << real << " " << imag << " "
         << thisCount << "\n";
  }
  ~Complex() { cout << "In the destructor of obj " << thisCount << "\n"; }
  Complex(const Complex &c);
  Complex &operator=(const Complex &c);
  Complex(Complex &&c);
  Complex &operator=(Complex &&c);

  double realPart() const { return this->real; }
  double imagPart() const { return this->imag; }
};

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

Complex Conjugate(const Complex z) {
  std::cout << "Inside Conjugate(): " << z << '\n';
  auto r = z.realPart();
  auto i = z.imagPart();
  Complex z2{r, -i};
  return z2;
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
void swap(Complex &z1, Complex &z2) {
  auto temp{std::move(z1)};
  z1 = std::move(z2);
  z2 = std::move(temp);
}

int main() {
  Complex z1(4, 5), z2(5, 3);
  cout << z1 << " " << z2 << '\n';
  Complex z3{z1};
  Complex z4 = z2;
  auto z5 = Conjugate(z4);
  cout << "z5: " << z5 << " \n";
  swap(z1, z2);
  cout << z1 << " " << z2 << '\n';
  return 0;
}
