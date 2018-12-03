//
// Created by Shawn Elbaz on 2018-11-05.
//

#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <boost/algorithm/string/classification.hpp> // Include boost::for is_any_of
#include <boost/algorithm/string/split.hpp> // Include for boost::split

using namespace std;

namespace libString
{
    template <typename T> string to_string(const T& n)
    {
        ostringstream stream;
        stream << n;
        return stream.str();
    }

    static vector<string> stringtoArray(string s){
        std::vector<std::string> words;
        boost::split(words, s, boost::is_any_of(":"), boost::token_compress_on);
        return words;
    }

    static int ofToInt(string str) {
        istringstream stream(str);
        int result;
        stream >> result;
        return result;
    }
}