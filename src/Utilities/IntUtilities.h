#pragma once

#include <string>

class IntUtilities
{
  public:
    /// \brief  Converts an integer to a hex (std) string
    /// \param  value: value to convert, only positive numbers
    /// \return the hex string
    static std::string ToHexString(int value);

  private:
    /// \brief Utility class, no constructor
   IntUtilities();
};
