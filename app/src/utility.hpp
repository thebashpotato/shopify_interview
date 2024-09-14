#pragma once

#include <algorithm>
#include <cctype>
#include <string>

namespace rover
{

inline auto to_upper(std::string s) -> std::string
{
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::toupper(c); } // correct
    );
    return s;
}

} // namespace rover
