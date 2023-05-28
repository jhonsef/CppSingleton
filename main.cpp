#ifndef MAIN
#define MAIN

#include <iostream>
#include <thread>
#include <chrono>

#include "./Singleton.hpp"

using namespace std;

void ThreadOoone()
{
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    const Singleton *s{Singleton::getInstance("Ooone Guy")};
    s->showMessage();
    s->showMessageSize();
}

void ThreadTwooo()
{
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    const Singleton *s{Singleton::getInstance("Twooo guy")};
    s->showMessage();
    s->showMessageSize();
}

int main()
{
    std::cout << "If you see the same value, then singleton was reused (yay!\n"
              << "If you see different values, then 2 singletons were created (booo!!)\n\n"
              << "RESULT:\n";
    std::thread t1(ThreadOoone);
    std::thread t2(ThreadTwooo);
    t1.join();
    t2.join();
    return 0;
}

#endif ///@note end of MAIN