// /*
//
// ###    #####             #
// #   #  #     #           ##
// # #   #       #          # #
// #  #  #  #####   #####     #
// #   # # #                  #
// #   #  #                  #
// ###   #######          #####
// */
//
// #include <iostream>

// int max(int a, int b) { return a > b ? a : b; }
// double max(double a, double b) { return a > b ? a : b; }

// int main() {
//   std::cout << "Enter two numbers: ";
//   // Will fail if it is double p, q!
//   // Will fail for max(3, 4.5)
//   int p, q;
//   std::cin >> p >> q;
//   std::cout << "The larger number is: " << max(p, q) << '\n';
// }

//
// /*
// ###    #####           #####
// #   #  #     #         #     #
// # #   #       #               #
// #  #  #  #####   #####   #####
// #   # # #               #
// #   #  #               #
// ###   #######         #######
// */
// #include <iostream>

// template <typename T> T max(T a, T b) { return a > b ? a : b; }
// int main() {
//   std::cout << "The larger number between " << 3 << " and " << 5
//             << " is: " << max(3, 5) << '\n';
//   std::cout << "The larger number between " << 3.2 << " and " << 5.3
//             << " is: " << max(3.2, 5.3) << '\n';
//   std::cout << "The larger char between " << 'f' << " and " << 'p'
//             << " is: " << max('f', 'p') << '\n';
//   return 0;
// }

/*
  ###    #####           #####
 #   #  #     #         #     #
# #   #       #               #
#  #  #  #####   #####   #####
#   # # #                     #
 #   #  #               #     #
  ###   #######          #####
*/
#include <gurobi_c++.h>
#include <iostream>

bool operator>(GRBVar v1, GRBVar v2) {
  return v1.get(GRB_DoubleAttr_X) > v2.get(GRB_DoubleAttr_X);
}
template <typename T> T max(T a, T b) { return a > b ? a : b; }

void gurobifn() {
  GRBEnv e;
  GRBModel model(e);
  GRBVar x = model.addVar(0, 1, 1, GRB_BINARY, "x");
  GRBVar y = model.addVar(0, 1, 1, GRB_BINARY, "y");
  GRBVar z = model.addVar(0, 1, 1, GRB_BINARY, "z");
  model.addConstr(x + y >= 1);
  model.addConstr(z + y >= 1);
  model.addConstr(x + z >= 1);
  model.optimize();

  std::cout << "Optimal solution:\n";
  std::cout << x.get(GRB_StringAttr_VarName)
            << " :
               "<<x.get(GRB_DoubleAttr_X)<<'\n'; std::cout <<
               y.get(GRB_StringAttr_VarName)
            << " : " << y.get(GRB_DoubleAttr_X) << '\n';
  std::cout << z.get(GRB_StringAttr_VarName)
            << " :
               "<<z.get(GRB_DoubleAttr_X)<<'\n';

      GRBVar ans = max(x, y);
  std::cout << "The larger variable between " << x.get(GRB_StringAttr_VarName)
            << " and " << y.get(GRB_StringAttr_VarName)
            << " is: " << ans.get(GRB_StringAttr_VarName) << '\n';
}

int main() {
  std::cout << "The larger number between " << 3 << " and " << 5
            << " is: " << max(3, 5) << '\n';
  std::cout << "The larger number between " << 3.2 << " and " << 5.3
            << " is: " << max(3.2, 5.3) << '\n';
  std::cout << "The larger char between " << 'f' << " and " << 'p'
            << " is: " << max('f', 'p') << '\n';
  gurobifn();
}
