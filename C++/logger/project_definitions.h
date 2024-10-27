#pragma once

#include <string>

#define UNIX_COLOR_END_TAG "\033[m"

/*
 * Supported Log Colors
 * Limited to 256 colors
 */
enum class EPrintColor : unsigned char
{
    Red,
    Green,
    Blue,
    White,
    Black,
    Magenta,
    Cyan,
    Yellow,
    Gray,
    LightRed,
    LightGreen,
    LightBlue,
    LightWhite,
    LightMagenta,
    LightCyan,
    LightYellow
};

/*
 * Debug categories to filter Logs
 */
enum class ELogCategory : int
{
    Default,
    Error,
    Core,
    Editor,
    Component,
    Threads,
    AutoCount /* Should be last! Number of categories */
};

enum class ELogCategoryState : int
{
    Enabled,
    Disabled,
    AutoCount
};

/**
 * @brief Convert color to its coresponding ANSI code
 *
 * Color converter for Unix systems, compiled when DEBUG_MODE is defined(RELEASE_MODE optimization)
 *
 * @param color: enum color to be converted
 *
 * @return std::string: corresponding ANSI code
 */
inline std::string Color_To_Ansi(const EPrintColor color) noexcept
{
    switch (color)
    {
        case EPrintColor::Red:
            return "\033[1;31m";
            break;
        case EPrintColor::Green:
            return "\033[1;32m";
            break;
        case EPrintColor::Blue:
            return "\033[1;34m";
            break;
        case EPrintColor::White:
            return "\033[1;37m";
            break;
        case EPrintColor::Black:
            return "\033[1;30m";
            break;
        case EPrintColor::Magenta:
            return "\033[1;35m";
            break;
        case EPrintColor::Cyan:
            return "\033[1;36m";
            break;
        case EPrintColor::Yellow:
            return "\033[1;33m";
            break;
        case EPrintColor::Gray:
            return "\033[1;90m";
            break;
        case EPrintColor::LightRed:
            return "\033[1;91m";
            break;
        case EPrintColor::LightGreen:
            return "\033[1;92m";
            break;
        case EPrintColor::LightBlue:
            return "\033[1;94m";
            break;
        case EPrintColor::LightWhite:
            return "\033[1;97m";
            break;
        case EPrintColor::LightMagenta:
            return "\033[1;95m";
            break;
        case EPrintColor::LightCyan:
            return "\033[1;96m";
            break;
        case EPrintColor::LightYellow:
            return "\033[1;94m";
            break;
        default:
            return "\033[1;37m"; // return White by default
            break;
    }
}
