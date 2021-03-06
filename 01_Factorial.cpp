/*
  ###      #               #
 #   #    ##              ##
# #   #  # #             # #
#  #  #    #     #####     #
#   # #    #               #
 #   #     #               #
  ###    #####           #####
*/
//
// #include <iostream>
// //
// int main() {
//   std::cout << "Enter a number: ";
//   //
//   // Declare only before where the variable is needed
//   int n;
//   /*
//   int  - integer (4 bytes/8 bytes/16 bytes) @ - 2^32 to + 2^32
//   char  - -128 to +128 - 1 byte
//   double - 16/32
//   "Qualification" for int/char
//   unsigned int or signed int
//   long

//   */
//   std::cin >> n;
//   // https://github.com/ssriram1992/Cpp4Gerad
//   //
//   // long int fact = 1; <- bad practice.
//   long int fact{1L};
//   // for (initialization; checking; increment/final steps)
//   for (int i = 1; i < n + 1; i++)
//   	{
//   		fact *= i; // fact = fact*i;
//   	}
//   //
//   std::cout << n << " factorial is " << fact << '\n';
//   //
//   return 0;
// }

/*

  ###      #             #####
 #   #    ##            #     #
# #   #  # #                  #
#  #  #    #     #####   #####
#   # #    #            #
 #   #     #            #
  ###    #####          #######
*/
// #include <iostream>

// long int factorial(int n) {
//   long int fact{1L};
//   for (int i = 1; i < n + 1; i++)
//     fact *= i;
//   return fact;
// }

// int main() {
//   std::cout << "Enter a number: ";// cout << 1 << ' ' << 2
//   int n;
//   std::cin >> n;
//   std::cout << n << " factorial is " << factorial(n) << '\n';

//   return 0;
// }

/*
  ###      #             #####
 #   #    ##            #     #
# #   #  # #                  #
#  #  #    #     #####   #####
#   # #    #                  #
 #   #     #            #     #
  ###    #####           #####
*/
#include <exception>
#include <iostream>

using std::cin;
using std::cout;

long int factorial(int n) {
  if (n < 0)
    throw std::runtime_error(
        "Error in factorial(int): factorial not defined for negative integers");
  long int fact{1L};
  for (int i = 1; i < n + 1; i++)
    fact *= i;
  return fact;
}

int main() {
  cout << "Enter a number: ";
  int n;
  std::cin >> n;
  // Directly the below line might be bad!
  // std::cout << n << " factorial is " << factorial(n) << '\n';
  long int fact;
  try {
    fact = factorial(n);
    std::cout << n << " factorial is " << fact << '\n';
  } catch (std::runtime_error &e) {
    std::cout << "Exception caught: " << e.what() << '\n';
  } catch (std::overflow_error &e) {

  } catch (...) {
    std::cout << "Some stupid error\n"
  }

  std::cout << "Reaching the end of the function\n";
  return 0;
}
