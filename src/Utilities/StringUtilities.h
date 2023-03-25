#pragma once

#include <string>
#include <vector>

class StringUtilities
{
  public:
    static std::vector<std::string> ToStringVector(const std::string &text);

    static std::string Trim(const std::string &text);

    static void AssertTrimEqual(const std::string &string1, const std::string &string2);
    static std::string ParseStringKey(const std::string &line, const std::string &key);
    static int ParseIntKey(const std::string &line, const std::string &key, int minimumValue = 0,
                           int maximumValue = std::numeric_limits<int>::max());
    static double ParseDoubleKey(const std::string &line, const std::string &key, double minimumValue = 0.0,
                                 double maximumValue = std::numeric_limits<int>::max());

  private:
    StringUtilities();
};
