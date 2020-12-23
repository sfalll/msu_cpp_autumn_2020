#ifndef POLL_HPP
#define POOL_HPP

#include <thread>
#include <queue>
#include <mutex>
#include <future>
#include <vector>
#include <functional>

class ThreadPool{
private:
    size_t poolSize_;
    std::queue<std::packaged_task<void()>> tasks_;
    std::mutex mut_;
    std::vector<std::thread> threads_;
    std::condition_variable var_;
    bool finish_ = false;
    void tasks();
public:
    explicit ThreadPool(size_t PoolSize);
    ~ThreadPool();

    template <typename Func, typename... Args>
    auto exec(Func func, Args... args) -> std::future<decltype(func(args...))>;
};


template<typename Func, typename... Args>
auto ThreadPool::exec(Func func, Args... args) -> std::future<decltype(func(args...))>{
    std::packaged_task<decltype(func(args...))()> task(std::bind(func, std::forward<Args>(args)...));
    auto res = task.get_future();
    {
        std::unique_lock<std::mutex> lock(mut_);
        tasks_.emplace(std::move(task));
    }
    var_.notify_one();
    return res;
}

#endif