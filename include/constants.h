#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string_view>

namespace Constants
{

    // Register keywords
    inline constexpr std::string_view REG = "REG";
    inline constexpr std::string_view FIELD = "FIELD";

    // cmd line arg
    inline constexpr std::string_view OUT_JSON = "json";
}

#endif
