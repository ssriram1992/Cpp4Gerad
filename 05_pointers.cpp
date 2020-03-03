#include <iostream>

void increment(int *x)
{
	(*x)++;
}

int main() {
	int regInt1 {42};
	int *regInt1Point;
	regInt1Point = &regInt1;
	// Printing them
	std::cout << "regInt1: "<<regInt1<<'\n';
	std::cout << "regInt1Point: "<<regInt1Point<<'\n';
	std::cout << "*regInt1Point: "<<*regInt1Point<<'\n'; 

	*regInt1Point = 27;
	std::cout << "regInt1: "<<regInt1<<'\n';
	std::cout << "regInt1Point: "<<regInt1Point<<'\n';
	std::cout << "*regInt1Point: "<<*regInt1Point<<'\n'; 

	increment(regInt1Point);
	std::cout << "regInt1: "<<regInt1<<'\n';
	std::cout << "regInt1Point: "<<regInt1Point<<'\n';
	std::cout << "*regInt1Point: "<<*regInt1Point<<'\n'; 

	int array[5] = {1,2,3,4,5};
	int* arrPoint = &array[0];
	std::cout << arrPoint << " " << arrPoint + 1 << '\n';
	std::cout << *arrPoint << " " << *(arrPoint + 1) << '\n';

	// Don't use them unless absolutely necessary in modern code!
}




