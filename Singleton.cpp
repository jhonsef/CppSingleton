#include "Singleton.hpp"

Singleton *Singleton::m_instance = nullptr;
mutex Singleton::m_guard;

Singleton::Singleton(const string message) : m_message(message) {}

Singleton *Singleton::getInstance(const string &message)
{
    // std::lock_guard<std::mutex> lock(m_guard);
    if (!m_instance)
        m_instance = new Singleton(message);

    return m_instance;
}

void Singleton::showMessage() const
{
    cout << "Message content: " << m_message << endl;
}

void Singleton::showMessageSize() const
{
    cout << "Message size: " << m_message.size() << endl;
}