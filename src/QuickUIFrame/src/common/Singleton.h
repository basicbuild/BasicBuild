/*!
 * \file QuSingleton.h
 * \brief 线程安全的单例宏
 */
#ifndef QUSINGLETON_H
#define QUSINGLETON_H

#include <stdlib.h>
#include <mutex>

template <typename T>
class QuSingleton
{
public:
    static T *instance() {
        static std::once_flag std_once_flag;
        std::call_once(std_once_flag, [&]() {
            t = new (T)();
            atexit(destory);
        });
        return t;
    }

    ~QuSingleton() = default;

private:
    static void destory() {
        delete t;
        t = nullptr;
    }

    QuSingleton() = default;
    QuSingleton(const QuSingleton&) = delete;
    QuSingleton& operator=(const QuSingleton&) = delete;

private:
    static T* volatile t;
};

template <typename T>
T* volatile QuSingleton<T>::t = nullptr;

#endif // QUSINGLETON_H
