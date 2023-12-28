/*
Function that returns while a thread still 
has access to local variables
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
        for(unsigned j = 0; j < 1000000; ++j) {
            // Potential access to dangling reference
            do_something(_i);
        }
    }
};



int main() {
    int local_var = 0;
    func my_func(local_var);
    std::thread th(my_func);
    // Will not wait for the thread to finish
    // Thread may still be running
    // Calling detach() break the association of the thread with the thread object
    // This ensures that std::terminate is not called when the thread object is destroyed
    th.detach();

    //th.join() will be the simple brute force way to ensure 
    //the thread was finished before we exited the main function
}