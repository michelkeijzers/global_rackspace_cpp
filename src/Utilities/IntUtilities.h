#pragma once

#include <string>

class IntUtilities
{
  public:
    /// \brief  Converts an integer to a hex (std) string
    /// \param  value: value to convert, only positive numbers
    /// \return the hex string
    static std::string ToHexString(int value);

	 /// \brief  Converts an integer to a bool (0: false, otherwise true)
	 /// \param  value: value to convert
	 /// \return boolean
	 static bool ToBool(int value)
    {
         return value != 0;
	 }

  private:
    /// \brief Utility class, no constructor
   IntUtilities();
};
