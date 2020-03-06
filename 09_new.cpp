#include <cmath>
#include <iostream>
#include <vector>

#include "complex.h"

using std::cin;
using std::cout;

// COMPLEX ORGANIZED INTO A HEADER FILE

int main() {
  Complex z0{3.14159, 1.732};
  std::vector<Complex> zv;
  zv.push_back(z0);
  zv.at(0).reset(4, 5);
  cout << z0 << " " << zv.back();

  Complex z1{1.1, 1}, z2{2.2, 4}, z3{3.3, 9};
  Complex z4{4.1, 10};
  std::vector<Complex> z;
  cout << "Capacity of z: " << z.capacity() << '\n';
  z.push_back(z1);
  cout << "Added z1. Capacity of z: " << z.capacity() << '\n';
  z.push_back(z2);
  cout << "Added z2. Capacity of z: " << z.capacity() << '\n';
  z.push_back(z3);
  cout << "Added z3. Capacity of z: " << z.capacity() << '\n';
  return 0;
}
