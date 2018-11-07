//
// Created by Shawn Elbaz on 2018-11-05.
//

#pragma once

#include <string>
#include <sstream>

using namespace std;

namespace libString
{
    template <typename T> string to_string(const T& n)
    {
        ostringstream stream;
        stream << n;
        return stream.str();
    }
}