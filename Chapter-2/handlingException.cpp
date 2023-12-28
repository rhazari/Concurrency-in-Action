/*
Handling the scenarion when exception gets 
thrown before making the call to join() the thread
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



int main() {
    int local_var = 0;
    func my_func(local_var);
    std::thread th(my_func);
    try {
        for(unsigned j = 0; j < 10000; ++j) {
            std::cout<<"Running from main\n";
        }
    }
    catch(...) {
        th.join();
        std::cout<<"Caught an exception\n";
    }
    th.join();
}