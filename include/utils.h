#ifndef UTILS_H
#define UTILS_H

#include <string_view>
#include <vector>

namespace Utils{

    // Trim leading
    std::string_view trim(std::string_view sv);

    // Split
    std::vector<std::string_view> split(std::string_view sv, const char spliter);
}

#endif