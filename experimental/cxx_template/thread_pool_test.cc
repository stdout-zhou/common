#include "thread_pool.h"

#include <chrono>
#include <iostream>
#include <vector>

std::mutex mx;

int main() {
  stdout_cxx_template::ThreadPool pool(10);

  auto sum = [](int l, int r) {
    int sum = 0;
    for (int i = l; i <= r; ++i) {
      sum += i;
    }
    return sum;
  };

  int s = 0;
  std::vector<std::future<int>> res_list;
  for (int i = 1; i + 99 <= 10000; i += 100) {
    int l = i, r = i + 99;
    res_list.push_back(pool.SubmitTask(sum, l, r));
  }
  for (int i = 0; i < res_list.size(); ++i) {
    s += res_list[i].get();
  }
  std::cout << s << std::endl;
  std::cout << (1 + 10000) * 10000 / 2 << std::endl;
  pool.Stop();
}
