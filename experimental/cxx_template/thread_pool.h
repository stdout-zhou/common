/*
线程池，可以提交任意的工作函数，并且支持异步的查询结果。
实现思路：
  普通版本的线程池 + std::future + 不定参数模板
*/

#pragma once

#include <condition_variable>
#include <functional>
#include <future>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

#include <iostream>

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

  template <typename Functor, typename... Args>
  auto SubmitTask(Functor&& functor, Args&&... args) -> std::future<decltype(functor(args...))>;

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

template <typename Functor, typename... Args>
auto ThreadPool::SubmitTask(Functor&& functor, Args&&... args) -> std::future<decltype(functor(args...))> {
  using ReturnType = decltype(functor(args...));
  // std::packaged_task<ReturnType()> async_task(std::bind(std::forward<Functor>(functor), std::forward<Args>(args)...));
  //std::packaged_task只能移动不能拷贝
  auto async_task = std::make_shared<std::packaged_task<ReturnType()>>(
      std::bind(std::forward<Functor>(functor), std::forward<Args>(args)...)
  ); 
  
  std::future<ReturnType> future_result = async_task->get_future();

  {
    std::unique_lock<std::mutex> lk(mx_);
    task_queue_.push([async_task](){
      (*async_task)();
    });
  }

  cv_.notify_one();

  return future_result;
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
