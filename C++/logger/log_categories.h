#pragma once

/*
 * TODO(Alex): Add API for runtine disabling/enabling of the categories. Maybe with IMGUI
 * TODO(Alex): Add name support for each category(optionally show the category name)
 */

#include <map>
#include "singleton.h"
#include "project_definitions.h"

/**
 * @brief Manages logging categories and their states.
 *
 * The `LogManager` class is responsible for managing the enabled or disabled
 * state of various logging categories. It allows enabling or disabling specific
 * logging categories and checking their current state. This class is a singleton
 * and inherits from the `Singleton` class template.
 *
 * @note
 * - This class uses the `ELogCategory` enum to represent different logging categories
 *   and `ELogCategoryState` to represent their enabled/disabled state.
 * - All logging categories are initialized as enabled by default.
 *
 * @tparam LogManager A singleton that ensures only one instance of the `LogManager` class exists.
 *
 * Example usage:
 * @code
 * LogManager* logManager = LogManager::GetInstance();
 * logManager->DisableCategory(ELogCategory::Debug);  // Disable debug category
 * if (logManager->IsCategoryEnabled(ELogCategory::Default)) {
 *     std::cout << "Default logging is enabled." << std::endl;
 * }
 * @endcode
 */
class LogManager : public Singleton<LogManager>
{
public:

    /**
     * @brief Constructs the `LogManager` and initializes all categories as enabled.
     *
     * This constructor initializes all logging categories to `Enabled` by default.
     * The number of categories is determined by `ELogCategory::AutoCount`, which
     * represents the total number of available logging categories.
     */
    LogManager() noexcept
    {
        for (int i = 0; i < static_cast<int>(ELogCategory::AutoCount); ++i)
        {
            logCategoryStates[static_cast<ELogCategory>(i)] = ELogCategoryState::Enabled;
        }
    }

    /**
     * @brief Enables a specific logging category.
     *
     * This function enables the specified logging category, allowing log messages
     * from this category to be processed.
     *
     * @param category The logging category to enable.
     */
    void EnableCategory(ELogCategory category)
    {
        logCategoryStates[category] = ELogCategoryState::Enabled;
    }

    /**
     * @brief Disables a specific logging category.
     *
     * This function disables the specified logging category, preventing log messages
     * from this category from being processed.
     *
     * @param category The logging category to disable.
     */
    void DisableCategory(ELogCategory category)
    {
        logCategoryStates[category] = ELogCategoryState::Disabled;
    }

    /**
     * @brief Checks if a specific logging category is enabled.
     *
     * This function checks if the specified logging category is currently enabled.
     *
     * @param category The logging category to check.
     * @return `true` if the category is enabled, `false` otherwise.
     */
    bool IsCategoryEnabled(ELogCategory category) const
    {
        return logCategoryStates.at(category) == ELogCategoryState::Enabled;
    }

    /**
     * @brief Checks if a specific logging category is disabled.
     *
     * This function checks if the specified logging category is currently disabled.
     *
     * @param category The logging category to check.
     * @return `true` if the category is disabled, `false` otherwise.
     */
    bool IsCategoryDisabled(ELogCategory category) const
    {
        return logCategoryStates.at(category) == ELogCategoryState::Disabled;
    }

private:
    /**
     * @brief Stores the state (enabled/disabled) of each logging category.
     *
     * This map holds the current state of all logging categories, where the key is
     * an `ELogCategory` enum and the value is an `ELogCategoryState` enum.
     */
    std::map<ELogCategory, ELogCategoryState> logCategoryStates;
};
