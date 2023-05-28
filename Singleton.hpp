#ifndef SINGLETON
#define SINGLETON

#include <string>
#include <iostream>
#include <mutex>

using namespace std;

class Singleton
{
protected:
    static Singleton *m_instance;
    static mutex m_guard;
    string m_message;

    Singleton(const string message);
    ~Singleton() = default;

public:
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

    static Singleton *getInstance(const string &message);

    void showMessage() const;
    void showMessageSize() const;
};
#endif