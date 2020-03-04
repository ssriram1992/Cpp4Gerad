#include <iostream>

void increment(int *x) { (*x)++; }

int main() {

  // Don't use them unless absolutely necessary in modern code!
  int regInt1{42};
  int *regInt1Point = nullptr;
  regInt1Point = &regInt1;
  // Printing them
  std::cout << "regInt1: " << regInt1 << '\n';
  std::cout << "regInt1Point: " << regInt1Point << '\n';
  std::cout << "*regInt1Point: " << *regInt1Point << '\n';

  *regInt1Point = 27;
  std::cout << "regInt1: " << regInt1 << '\n';
  std::cout << "regInt1Point: " << regInt1Point << '\n';
  std::cout << "*regInt1Point: " << *regInt1Point << '\n';

  increment(regInt1Point);
  std::cout << "regInt1: " << regInt1 << '\n';
  std::cout << "regInt1Point: " << regInt1Point << '\n';
  std::cout << "*regInt1Point: " << *regInt1Point << '\n';

  int array[5] = {1, 2, 3, 4, 5};
  int *arrPoint = &array[0];
  std::cout << arrPoint << " " << arrPoint + 1 << '\n';
  std::cout << *arrPoint << " " << *(arrPoint + 1) << '\n';

  std::cout << "\n\n const\n";

  const int regInt2{2};
  int regInt3{3};
  const int *regInt2P = nullptr;
  regInt2P = &regInt2;
  std::cout << "1: " << *regInt2P << '\n';
  regInt2P = &regInt1;
  std::cout << "2: " << *regInt2P << '\n';

  // *regInt2P = 4; // This is Error
  int *const regInt3P = &regInt1;
  std::cout << "3: " << *regInt3P << '\n';
  // regInt3P = &regInt3; // This is Error

  std::cout << *regInt2P << " " << *regInt2P << '\n';
}
