/*
Using RAII to wait for thread to complete
*/

#include <iostream>
#include <thread>

void do_something(int i) {
    std::cout<<"Executing something\n";
}

class func{
    int &_i;
public:
    func(int &i):_i(i){}

    void operator()(){
        for(unsigned j = 0; j < 10000; ++j) {
            do_something(_i);
        }
    }
};

class thread_guard {
    std::thread &_th;
public:
    explicit thread_guard(std::thread& t):_th(t){}

    ~thread_guard(){
        // join() can only be called once for a given thread
        // Checking if a thread is joinable before calling join()
        if(_th.joinable()) {
            _th.join();
        }
    }

    // These are deleted so that the compiler does not automatically provide them
    thread_guard(thread_guard const&)=delete;
    thread_guard& operator=(thread_guard const&)=delete;
};


int main() {
    int local_var = 0;
    func my_func(local_var);
    std::thread th(my_func);
    thread_guard guard(th);

    for(unsigned j = 0; j < 10000; ++j) {
            std::cout<<"Running from main\n";
    }
}