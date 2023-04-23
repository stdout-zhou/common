#include "tuple.h"

#include <iostream>
#include <string>

int main() {
  stdout_cxx_template::Tuple<std::string, int, double> tuple_1 = 
    stdout_cxx_template::Tuple<std::string, int, double>("test", 123, 3.14);
  std::cout << stdout_cxx_template::get<0>(tuple_1) << std::endl;
  std::cout << stdout_cxx_template::get<1>(tuple_1) << std::endl;
  std::cout << stdout_cxx_template::get<2>(tuple_1) << std::endl;
}
