/*!
 * \file YSingleton.h
 * \brief 线程安全的单例宏
 */
#ifndef SINGLETON_H
#define SINGLETON_H

#include <stdlib.h>
#include <mutex>
#include "Base_global.h"

template <typename T>
class BASE_EXPORT Singleton
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

    ~Singleton() = default;

private:
    static void destory() {
        delete t;
        t = nullptr;
    }

    Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    static T* volatile t;
};

template <typename T>
T* volatile Singleton<T>::t = nullptr;

#endif // SINGLETON_H
