#include "pool.hpp"

ThreadPool::ThreadPool(size_t poolSize) : poolSize_(poolSize){
    for(size_t i = 0; i < poolSize_; i++)
        threads_.push_back(std::thread([this](){tasks();}));
}

ThreadPool::~ThreadPool(){
    {
        std::unique_lock<std::mutex> lock(mut_);
        finish_ = true;
    }

    var_.notify_all();
    for(auto& t: threads_)
        t.join();
}

void ThreadPool::tasks(){
    while(true){
        std::packaged_task<void()> task;
        {
            std::unique_lock<std::mutex> lock(mut_);
            var_.wait(lock, [this](){return !tasks_.empty() || finish_;});
            if(finish_)
                return;
            task = std::move(tasks_.front());
            tasks_.pop();
        }
        task();
    }
}