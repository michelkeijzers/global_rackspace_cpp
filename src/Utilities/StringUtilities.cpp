#include "StringUtilities.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* static */ std::vector<std::string> StringUtilities::ToStringVector(const std::string &text)
{
    vector<std::string> lines;
    size_t start = 0, end = 0;
    while ((end = text.find("\r", start)) != string::npos)
    {
        lines.push_back(text.substr(start, end - start));
        start = end + 2;
    }
    lines.push_back(text.substr(start));
    return lines;
}
