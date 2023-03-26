#pragma once

#include "IntUtilities.h"

class ArrayUtilities
{
 public:
   /// \brief  Converts an array of integers with values upto 256 to a hex string
   /// \param  array: array to be converted
   /// \param  length: length of the array
   /// \return the hex string
   static std::string ToHexString(const uint8_t *data, int length);

 private:
   /// \brief Utility class, no constructor
   ArrayUtilities();
};
