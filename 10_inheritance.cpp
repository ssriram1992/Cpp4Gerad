#include "complex.h"
#include <iostream>

class rootsOfUnity : public Complex {
private:
  static constexpr double tol{1e-5};
  unsigned int n; // n-th root of unity
public:
  rootsOfUnity(const double r, const double i, const unsigned int n)
      : Complex(r, i) {
    Complex ans{r, i}, z{r, i};
    for (unsigned int i = 1; i < n; i++) {
      ans = ans * z;
    }
    if (ans.realPart() != 1 || ans.imagPart() != 0)
      throw std::string("Not a root of Unity");
  }
};
