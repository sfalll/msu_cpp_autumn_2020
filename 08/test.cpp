#include "pool.hpp"
#include <iostream>
#include <cassert>

struct A{
    int x = 3;
    int y = 4;
    int z = 5;
};

bool foo(const A& a){
    return ((a.x * a.x + a.y * a.y) == (a.z * a.z));
}

void BasicTets(){
    ThreadPool pool(std::thread::hardware_concurrency());

    auto task = pool.exec(foo, A());
    assert(task.get());
}

void ManyRoutineTest(){
    ThreadPool pool(std::thread::hardware_concurrency());

    std::vector<std::future<int>> ans;

    for(int i = 0; i < 100; i++)
        ans.push_back(pool.exec([](int a, int b){return a * b;}, i, 10));
    
    for(int i = 0; i < 100; i++)
        assert(ans[i].get() == i * 10);
}

int main(){
    BasicTets();
    ManyRoutineTest();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}

