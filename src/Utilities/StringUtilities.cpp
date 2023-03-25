#include "StringUtilities.h"
#include <iostream>
#include <string>
#include <vector>
#include "Debug.h"

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

/* static */ std::string StringUtilities::Trim(const std::string& text)
{
    std::string trimmedString;
    {
        const std::string whitespace = " \t\r\n";
        const std::size_t start = text.find_first_not_of(whitespace);
        if (start != std::string::npos)
        {
            const std::size_t end = text.find_last_not_of(whitespace);
            trimmedString = text.substr(start, end - start + 1);
        }
        else
        {
            trimmedString = text;
        }
    }
    return trimmedString;
}

/* static */ void StringUtilities::AssertTrimEqual(const std::string &string1, const std::string &string2)
{
    bool equal = (Trim(string1) == Trim(string2));
    Debug::Assert(equal, __FUNCTION__, "Strings " + string1 + " and " + string2 + " are not equal");
}

/* static */ std::string StringUtilities::ParseStringKey(const std::string& line, const std::string& key)
{
    size_t index = line.find(":");
    Debug::Assert(index != std::string::npos, __FUNCTION__, "Delimiter character not found");
    Debug::Assert(Trim(line.substr(0, index)) == key, __FUNCTION__, "Key " + key + " not found");
    return Trim(line.substr(index + 1));
}

/* static */ int StringUtilities::ParseIntKey(const std::string &line, const std::string &key,
                                              int minimumValue /* = 0 */,
                                              int maximumValue /* = std::numeric_limits<int>::max() */)
{
    size_t index = line.find(":");
    Debug::Assert(index != std::string::npos, __FUNCTION__, "Delimiter character not found");
    Debug::Assert(Trim(line.substr(0, index)) == key, __FUNCTION__, "Key " + key + " not found");
    int value = -1;
    try
    {
        value = std::stoi(Trim(line.substr(index + 1)));
        Debug::Assert(value >= minimumValue, __FUNCTION__, "Value too small");
        Debug::Assert(value <= maximumValue, __FUNCTION__, "Value too high");
    }
    catch (const std::invalid_argument &e)
    {
        Debug::Error(__FUNCTION__, "Invalid argument");
    }
    return value;
}

/* static */ double StringUtilities::ParseDoubleKey(const std::string &line, const std::string &key,
                                                    double minimumValue /* = 0.0 */, double maximumValue /* = 1.0 */)
{
    size_t index = line.find(":");
    Debug::Assert(index != std::string::npos, __FUNCTION__, "Delimiter character not found");
    Debug::Assert(Trim(line.substr(0, index)) == key, __FUNCTION__, "Key " + key + " not found");
    double value = -1;
    try
    {
        value = std::stod(Trim(line.substr(index + 1)));
        Debug::Assert(value >= minimumValue, __FUNCTION__, "Value too small");
        Debug::Assert(value <= maximumValue, __FUNCTION__, "Value too high");
    }
    catch (const std::invalid_argument &e)
    {
        Debug::Error(__FUNCTION__, "Invalid argument");
    }
    return value;
}
