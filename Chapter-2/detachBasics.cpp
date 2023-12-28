/*
Calling detach() on a std::thread make the thread run in the background

No longer possible to communicate with the thread that has been detached
Not possible to obtain the thread object for a detached thread

Detached threads run in the background and the control is passed over to the 
C++ Runtime

Ideally should use detached threads for long running processes, such as
- performing background task for monitoring filesystems
- clearing unused entries out of object caches

A detached thread is no longer joinable
std::thread th(func);
th.detach();
assert(!th.joinable());
*/