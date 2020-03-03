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
// #include<iostream>
//
// int main()
// {
// std::cout << "Enter a number: ";
//
// // Declare only before where the variable is needed
// int n;
// std::cin >> n;
//
// long int fact {1L};
// for(int i=1;i<n+1;i++)
// fact*=i;
//
// std::cout << n <<" factorial is "<<fact<<'\n';
//
// return 0;
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
// #include<iostream>
//
// long int factorial(int n){
// long int fact{1L};
// for (int i=1; i < n+1; i++ )
// fact*=i;
// return fact;
// }
//
// int main()
// {
// std::cout << "Enter a number: ";
// int n;
// std::cin >> n;
// std::cout << n <<" factorial is "<<factorial(n)<<'\n';
//
// return 0;
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
// #include <exception>
// #include <iostream>
//
// long int factorial(int n) {
// if (n < 0)
// throw std::runtime_error(
// "Error in factorial(int): factorial not defined for negative integers");
// long int fact{1L};
// for (int i = 1; i < n + 1; i++)
// fact *= i;
// return fact;
// }
//
// int main() {
// std::cout << "Enter a number: ";
// int n;
// std::cin >> n;
// // Directly the below line might be bad!
// // std::cout << n << " factorial is " << factorial(n) << '\n';
// long int fact;
// try {
// fact = factorial(n);
// std::cout << n << " factorial is " << fact << '\n';
// } catch (std::exception &e) {
// std::cout << "Exception caught: " << e.what() << '\n';
// }
//
// return 0;
// }
