/*
v1版本的线程池，只能支持提交std::function<void()>的任务，待补充...
*/

#pragma once

#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

namespace stdout_cxx_template {

class ThreadPool {
public:
  using Task = std::function<void()>;
  ThreadPool(int8_t thread_num) {
    thread_num_ = std::min(thread_num, static_cast<int8_t>(std::thread::hardware_concurrency()));

    pool_.resize(thread_num_);
    for (int i = 0; i < thread_num_; ++i) {
      pool_[i] = std::thread(&ThreadPool::Work, this);
    }

    stop_ = false;
  }

  void SubmitTask(Task task);

  void Stop();
private:
  int8_t thread_num_;
  std::vector<std::thread> pool_;
  std::condition_variable cv_;
  std::mutex mx_;
  bool stop_;
  
  std::queue<Task> task_queue_;

  void Work();
  
};

////////////////////////////// Implement //////////////////////////////

void ThreadPool::Work() {
  while (true) {
    ThreadPool::Task task;
    {
      std::unique_lock<std::mutex> lk(mx_);
      cv_.wait(lk, [this](){ 
        return task_queue_.size() > 0 || stop_;
      });
      // 其实这里不用判断stop_,
      // 因为如果task_queue是空的，但是这个线程被唤醒了说明此时pool已经
      // 执行了Stop。
      if (task_queue_.empty() && stop_) {
        return;
      }
      task = task_queue_.front();
      task_queue_.pop();
    }
    task();
  }
}

void ThreadPool::SubmitTask(ThreadPool::Task task) {
  {
    std::unique_lock<std::mutex> lk(mx_);
    task_queue_.push(task);
  }
  cv_.notify_one();
}

void ThreadPool::Stop() {
  stop_ = true;
  {
    std::unique_lock<std::mutex> lk(mx_);
    cv_.notify_all();
  }
  for (int i = 0; i < thread_num_; ++i) {
    pool_[i].join();
  }
}

} // namespace stdout_cxx_template
