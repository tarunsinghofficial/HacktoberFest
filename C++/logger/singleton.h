#pragma once

#include <mutex>

/**
 * @file Singleton.h
 * @brief A thread-safe template class for implementing the Singleton design pattern.
 *
 * The `Singleton` class provides a simple way to create a singleton instance
 * of a class using the Curiously Recurring Template Pattern (CRTP). It ensures that
 * only one instance of the class exists and provides global access to that instance.
 *
 * Usage Example:
 * @code
 * class MySingleton : public Singleton<MySingleton>
 * {
 *     // Singleton-specific methods
 * };
 *
 * void SomeFunction()
 * {
 *     MySingleton* instance = MySingleton::GetInstance();
 * }
 * @endcode
 *
 * @tparam T The type of the singleton class that inherits from `Singleton`.
 */
template <typename T>
class Singleton
{
public:
    /**
     * @brief Retrieves the singleton instance.
     *
     * If the instance does not exist, it is created. This method returns a pointer
     * to the singleton instance.
     * The Double-Checked Locking Pattern for optimized thread safety, if the program uses the GetInstance
     * function N times with this pattern the lock will be aquired only the first time instead of N times.
     *
     * @return T* A pointer to the singleton instance.
     */
    static T* GetInstance()
    {
        if(!m_instance)
        {
            const std::lock_guard<std::mutex> lock(m_lock);
            if(!m_instance)
            {
                m_instance = new T;
            }
        }
        return m_instance;
    }

    /**
     * @brief Retrieves the singleton instance by reference.
     *
     * If the instance does not exist, it is created. This method returns a reference
     * to the singleton instance.
     * The Double-Checked Locking Pattern for optimized thread safety.
     *
     * @return T& A reference to the singleton instance.
     */
    static T& GetRef()
    {
        if(!m_instance)
        {
            const std::lock_guard<std::mutex> lock(m_lock);
            if(!m_instance)
            {
                m_instance = new T;
            }
        }
        return *m_instance;
    }

    /**
     * @brief Destroys the singleton instance.
     *
     * This method deletes the singleton instance and sets the instance pointer to null.
     * All references to the singleton instance will be invalid after this method is called.
     * The Double-Checked Locking Pattern for optimized thread safety.
     */
    static void DestroyInstance()
    {
        if(m_instance)
        {
            std::lock_guard<std::mutex> lock(m_lock);
            delete m_instance;
            m_instance = nullptr;
        }
    }

    /**
     * @brief Prevents moving or copying the singleton instance.
     *
     * This ensures that the singleton instance cannot be copied or moved, preserving
     * the unique instance guarantee.
     */
    Singleton(Singleton&& source) = delete;
    Singleton(const Singleton& source) = delete;
    Singleton& operator=(Singleton&& source) = delete;
    const Singleton& operator=(const Singleton& source) = delete;

protected:
    /**
     * @brief Protected constructor for the Singleton class.
     *
     * This prevents external classes from creating instances of the singleton directly.
     */
    Singleton() = default;

    /**
     * @brief Protected destructor for the Singleton class.
     *
     * This cleans up the singleton instance when it is destroyed.
     */
    ~Singleton()
    {
        delete m_instance;
        m_instance = nullptr;
    }

private:
    /**
     * @brief Static pointer to the singleton instance.
     *
     * This static member variable holds the instance of the singleton class.
     * inlined so it can be class initialized
     */
    inline static T* m_instance{nullptr};
    /**
     * @brief Static mutex for thread safety.
     *
     * Avoids memory leaks as two threads can create a race condition with the m_instance.
     */
    inline static std::mutex m_lock{};
};

