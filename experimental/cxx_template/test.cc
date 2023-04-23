#include <iostream>

struct test{
  using type = int;
};

int main() {
  test::type x = 100;  
  
}