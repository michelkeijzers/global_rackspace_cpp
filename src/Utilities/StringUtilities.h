#pragma once

#include <string>
#include <vector>

class StringUtilities
{
  public:
    static std::vector<std::string> ToStringVector(const std::string &text);

  private:
    StringUtilities();
};
