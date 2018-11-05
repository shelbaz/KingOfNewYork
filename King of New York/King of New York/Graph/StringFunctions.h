//
// Created by Shawn Elbaz on 2018-11-05.
//

#pragma once

#include <string>
#include <sstream>

namespace libString
{
    template <typename T> std::string to_string(const T& n)
    {
        std::ostringstream stream;
        stream << n;
        return stream.str();
    }
}