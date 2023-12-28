/*
Thread taking in an instance of a class
*/

#include <iostream>
#include <thread>

void func1() {
    std::cout<<"Here in func1\n";
}

void func2() {
    std::cout<<"Now in func2\n";
}

class background_task{

public:
    void operator()() const {
        std::cout<<"Getting called explicitly\n";
        func1();
        func2();
    }
};

int main() {
    
    background_task task;

    // Passing an instance of a class with the function call operator
    //std::thread th(task);

    // Avoid C++ most vexing parse
    // Using extra set of ()
    //std::thread th((background_task()));

    // Using uniform initialization
    std::thread th{background_task()};
}