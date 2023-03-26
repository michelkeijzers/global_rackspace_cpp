#include "StringUtilities.h"
#include <iostream>
#include <string>
#include <vector>
#include "Debug.h"
#include <map>

using namespace std;

static std::pair<std::string, bool> StringToBoolMappingPairs[] = {
    std::make_pair("0", false),     std::make_pair("f", false),     std::make_pair("F", false),
    std::make_pair("false", false), std::make_pair("False", false), std::make_pair("FALSE", false),
    std::make_pair("off", false),   std::make_pair("Off", false),   std::make_pair("OFF", false),
    std::make_pair("1", true),      std::make_pair("t", true),      std::make_pair("T", true),
    std::make_pair("true", true),   std::make_pair("True", true),   std::make_pair("TRUE", true),
    std::make_pair("on", true),     std::make_pair("On", true),     std::make_pair("ON", true),
};

static std::map<std::string, bool> StringToBoolMapping(StringToBoolMappingPairs,
	StringToBoolMappingPairs + sizeof StringToBoolMappingPairs / sizeof StringToBoolMappingPairs[0]);

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

/* static */ std::string StringUtilities::Trim(const std::string &text)
{
    std::string trimmedString;
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
    return trimmedString;
}

/* static */ bool StringUtilities::IsLegalBool(const std::string &stringToCheck, bool assertIsLegal /* = true */)
{
    auto it = StringToBoolMapping.find(stringToCheck);
    bool isLegal = it != StringToBoolMapping.end();
    if (assertIsLegal)
    {
        Debug::Assert(isLegal, __FUNCTION__, "bool not legal");
    }
    return isLegal;
}

/* static */ bool StringUtilities::ToBool(const std::string& stringToCheck)
{
     return StringToBoolMapping[stringToCheck];
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
    std::string valueAsString = Trim(line.substr(index + 1));
    try
    {
        value = std::stoi(valueAsString);
    }
    catch (const std::invalid_argument &e)
    {
        Debug::Error(__FUNCTION__, "Invalid argument");
    }
    Debug::Assert(value >= minimumValue, __FUNCTION__, "Value too small");
    Debug::Assert(value <= maximumValue, __FUNCTION__, "Value too high");
    return value;
}

/* static */ double StringUtilities::ParseDoubleKey(const std::string &line, const std::string &key,
                                                    double minimumValue /* = 0.0 */, double maximumValue /* = 1.0 */)
{
    size_t index = line.find(":");
    Debug::Assert(index != std::string::npos, __FUNCTION__, "Delimiter character not found");
    Debug::Assert(Trim(line.substr(0, index)) == key, __FUNCTION__, "Key " + key + " not found");
    double value = 0.0;
    std::string valueAsString = Trim(line.substr(index + 1));
    try
    {
        value = std::stod(valueAsString);
    }
    catch (const std::invalid_argument &e)
    {
        Debug::Error(__FUNCTION__, "Invalid argument");
    }
    Debug::Assert(value >= minimumValue, __FUNCTION__, "Value too small");
    Debug::Assert(value <= maximumValue, __FUNCTION__, "Value too high");
    return value;
}

/* static */ bool StringUtilities::ParseBooleanKey(const std::string &line, const std::string &key)
{
    size_t index = line.find(":");
    Debug::Assert(index != std::string::npos, __FUNCTION__, "Delimiter character not found");
    Debug::Assert(Trim(line.substr(0, index)) == key, __FUNCTION__, "Key " + key + " not found");
    std::string valueAsString = Trim(line.substr(index + 1));
    IsLegalBool(valueAsString, true);
    return ToBool(valueAsString);
}