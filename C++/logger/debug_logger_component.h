#pragma once

/*
 *
 * debug_logger_component.h is a collection of global variadic templated functions
 * with different overload options(color, time/date, and more to come).
 * The functionalities get compiled ONLY when DEBUG_MODE is defined in CMake,
 * otherwise the funcitons bodies are compiled empty to avoid Debug Logs in RELEASE_MODE(optimization).
 * TODO(Alex): debug_logger_component is planned to be a 'core' header that every class in the engine will have.
 *
 * !!! WARNINGS !!!
 * Shipped products(in RELEASE_MODE) should not rely on these functions as they are only compiled in DEBUG_MODE
 * However you do not need to delete them when shipping.
 * (warning)inline global function with external linkage have undefined behavior.
 *
 */

/* needed outside DEBUG_MODE to compile in all modes (EPrintColor)*/
#include "project_definitions.h"

#ifdef DEBUG_MODE

#include <iostream>
#include <chrono>
#include <ctime>

#include "log_categories.h"

#endif /* DEBUG_MODE */

/**
 * @brief Logs debug information to the console in debug mode.
 *
 * This function prints the provided arguments to the console, but only if
 * the application is compiled with `DEBUG_MODE` enabled. It uses variadic
 * templates to accept a flexible number of arguments and formats them as
 * a single line of output.
 *
 * @tparam Args Variadic template parameter representing the types of the arguments to be logged.
 * @param args The arguments to be printed. These can be of any type that is compatible with `std::ostream` (e.g., `std::cout`).
 *
 * @note
 * - This function only works when the `DEBUG_MODE` macro is defined during compilation.
 *   If `DEBUG_MODE` is not defined, the function has no effect.
 * - Before printing, the function checks whether the default logging category (`ELogCategory::Default`)
 *   is enabled. If it is disabled, no output is printed.
 * - The logging format starts with a prefix (`>>>`), followed by the arguments, each printed in sequence,
 *   and ends with a newline.
 *
 * @details
 * - The function uses the `LogManager` singleton to check whether the default log category is disabled.
 *   If the category is disabled, the function returns early without printing anything.
 * - The use of a fold expression `([&] { std::cout << args; } (), ...)` ensures that all arguments
 *   are printed in sequence, with no separator between them.
 * - This function is marked `noexcept` to ensure that it does not throw exceptions.
 *
 * Example usage:
 * @code
 * Debug_Log("This is a debug message with a number: ", 42);
 * // Output: >>> This is a debug message with a number: 42
 * @endcode
 */
template<class... Args>
inline void Debug_Log(Args&&... args) noexcept
{
#ifdef DEBUG_MODE
    // Get the LogManager instance and check if the default logging category is disabled
    LogManager* logManager = LogManager::GetInstance();
    if(logManager->IsCategoryDisabled(ELogCategory::Default))
    {
        return;
    }
    std::cout << ">>> ";
    ([&]
    {
        std::cout << args;
    } (), ...);
    std::cout << std::endl;
#endif /* DEBUG_MODE */
}

/**
 * @brief Print on console dynamic number of args with a print category
 *
 * The body of the function is only compiled in DEBUG_MODE(RELEASE_MODE optimization)
 *
 * @param  category: print category
 * @param ...args: dinamic number of arguments to print regardless of their type
 *
 * Example usage:
 * Debug_Log("Loading next level", 69, 420.69);
 *
 * @return void
 */
template<class... Args>
inline void Debug_Log(ELogCategory category, Args&&... args) noexcept
{
#ifdef DEBUG_MODE
    /* Do not print disabled categories */
    LogManager* logManager = LogManager::GetInstance();
    if(logManager->IsCategoryDisabled(category))
    {
        return;
    }
    std::cout << ">>> ";
    ([&]
    {
        std::cout << args;
    } (), ...);
    std::cout << std::endl;
#endif /* DEBUG_MODE */
}

/**
 * @brief Print on console dynamic number of args with color
 *
 * The body of the function is only compiled in DEBUG_MODE(RELEASE_MODE optimization)
 *
 * @param  color: print color
 * @param ...args: dinamic number of arguments to print regardles of their type
 *
 * Example usage:
 * Debug_Log(EPrintColor::Red, "Loading next level", 69, 420.69);
 *
 * @return void
 */
template<class... Args>
inline void Debug_Log(const EPrintColor color, Args&&... args) noexcept
{
#ifdef DEBUG_MODE
    /* Do not print if default category is disabled */
    LogManager* logManager = LogManager::GetInstance();
    if(logManager->IsCategoryDisabled(ELogCategory::Default))
    {
        return;
    }
    std::string color_code = Color_To_Ansi(color);
    std::cout << ">>> " << color_code;
    ([&]
    {
        std::cout << args;
    } (), ...);
    std::cout << UNIX_COLOR_END_TAG << std::endl;
#endif /* DEBUG_MODE */
}

/**
 * @brief Print on console dynamic number of args with color and a category
 *
 * The body of the function is only compiled in DEBUG_MODE(RELEASE_MODE optimization)
 *
 * @param  category: category to print in
 * @param  color: print color
 * @param ...args: dinamic number of arguments to print regardles of their type
 *
 * Example usage:
 * Debug_Log(EPrintColor::Red, "Loading next level", 69, 420.69);
 *
 * @return void
 */
template<class... Args>
inline void Debug_Log(const ELogCategory category, const EPrintColor color, Args&&... args) noexcept
{
#ifdef DEBUG_MODE
    /* Do not print disabled categories */
    LogManager* logManager = LogManager::GetInstance();
    if(logManager->IsCategoryDisabled(category))
    {
        return;
    }
    std::string color_code = Color_To_Ansi(color);
    std::cout << ">>> " << color_code;
    ([&]
    {
        std::cout << args;
    } (), ...);
    std::cout << UNIX_COLOR_END_TAG << std::endl;
#endif /* DEBUG_MODE */
}

/**
 * @brief Print on console dynamic number of args with color and time option
 *
 * The body of the function is only compiled in DEBUG_MODE(RELEASE_MODE optimization)
 *
 * @param  color: print color
 * @param  bShowTime: show date and time of function call
 * @param ...args: dinamic number of arguments to print regardles of their type
 *
 * Example usage:
 * Debug_Log(EPrintColor::Red, true, "Loading next level", 69, 420.69);
 *
 * @return void
 */
template<class... Args>
inline void Debug_Log(const EPrintColor color, const bool bShowTime, Args&&... args) noexcept
{
#ifdef DEBUG_MODE
    LogManager* logManager = LogManager::GetInstance();
    if(logManager->IsCategoryDisabled(ELogCategory::Default))
    {
        return;
    }
    if(bShowTime)
    {
        auto call_time = std::chrono::high_resolution_clock::now();
        auto time_struct = std::chrono::system_clock::to_time_t(call_time);
        std::cout << std::ctime(&time_struct);
    }
    std::string color_code = Color_To_Ansi(color);
    std::cout << ">>> " << color_code;
    ([&]
    {
        std::cout << args;
    } (), ...);
    std::cout << UNIX_COLOR_END_TAG << std::endl;
#endif /* DEBUG_MODE */
}

/**
 * @brief Print on console dynamic number of args with color, time and category option
 *
 * The body of the function is only compiled in DEBUG_MODE(RELEASE_MODE optimization)
 *
 * @param  category: print category
 * @param  color: print color
 * @param  bShowTime: show date and time of function call
 * @param ...args: dinamic number of arguments to print regardles of their type
 *
 * Example usage:
 * Debug_Log(ELogCategory::Engine, EPrintColor::Red, true, "Loading next level", 69, 420.69);
 *
 * @return void
 */
template<class... Args>
inline void Debug_Log(const ELogCategory category, const EPrintColor color, const bool bShowTime, Args&&... args) noexcept
{
#ifdef DEBUG_MODE
    /* Do not print disabled categories */
    LogManager* logManager = LogManager::GetInstance();
    if(logManager->IsCategoryDisabled(category))
    {
        return;
    }
    if(bShowTime)
    {
        auto call_time = std::chrono::high_resolution_clock::now();
        auto time_struct = std::chrono::system_clock::to_time_t(call_time);
        std::cout << std::ctime(&time_struct);
    }
    std::string color_code = Color_To_Ansi(color);
    std::cout << ">>> " << color_code;
    ([&]
    {
        std::cout << args;
    } (), ...);
    std::cout << UNIX_COLOR_END_TAG << std::endl;
#endif /* DEBUG_MODE */
}

