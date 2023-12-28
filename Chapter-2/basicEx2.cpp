/*
Launching a thread with Lambda
*/

#include <iostream>
#include <thread>

void func1() {
    std::cout<<"Here in func1\n";
}

void func2() {
    std::cout<<"Now in func2\n";
}

int main() {
    std::thread th([]{
        func1();
        func2();
    });
}