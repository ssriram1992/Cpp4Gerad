/*
  ###    #####             #
 #   #  #     #           ##
# #   # #                # #
#  #  # ######   #####     #
#   # # #     #            #
 #   #  #     #            #
  ###    #####           #####
*/
#include <iostream>
#include <array>

using std::cin;
using std::cout;

int main(){
	std::array<int, 5> myArr {};
	cout<<"Enter 5 numbers: ";
	for(int i=0; i<5; i++)
		cin>>myArr.at(i);
	cout << "The entered numbers are: ";
	for(int i=0; i<5; i++)
		cout << myArr.at(i) << ' ';
	cout << '\n';
	return 0;
}

/*
  ###    #####           #####
 #   #  #     #         #     #
# #   # #                     #
#  #  # ######   #####   #####
#   # # #     #         #
 #   #  #     #         #
  ###    #####          #######
*/

// #include <iostream>
// #include <vector>
// 
// using std::cin;
// using std::cout;
// 
// int main() {
  // std::vector<int> myVec{};
  // int n;
  // char choice{'y'};
  // while (choice == 'y') {
    // cout << "Enter a number: ";
    // cin >> n;
    // myVec.push_back(n);
    // // while (true) {
    // cout << "Do you want to enter another number (y/n)?";
    // cin >> choice;
    // // if (choice == 'y' || choice == 'n')
    // // break;
    // // else
    // // cout << "Invalid option - ";
    // // }
  // }
  // cout << "The entered numbers are: ";
  // for (int i = 0; i < myVec.size(); i++) {
    // cout << myVec.at(i) << " ";
  // }
  // cout << '\n';
// }
