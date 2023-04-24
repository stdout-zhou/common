#include "thread_pool.h"

#include <chrono>
#include <iostream>

std::mutex mx;

int main() {
  stdout_cxx_template::ThreadPool pool(10);
  std::this_thread::sleep_for(std::chrono::milliseconds(300));
  for (int i = 1; i <= 100; ++i) {
    pool.SubmitTask([i](){
      std::unique_lock<std::mutex> lk(mx);
      std::cout << i << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
    });
  }
  pool.Stop();
}
