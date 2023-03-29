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
   static bool ToBool(int value);

   /// \brief  Maps an input value in range [inputMin..inputMax] to range [outputMin..outputMax]
   /// \param  valueToMap Value to be mapped
   /// \param  inputMin   Minimum value of the input range
   /// \param  inputMax   Maximum value of the input range
   /// \param  outputMin  Minimum value of the output range
   /// \param  outputMax  Maximum value of the output range
   /// \returns value insidei the output range
   static int Map(int valueToMap, int inputMin, int inputMax, int outputMin, int outputMax);

 private:
   /// \brief Utility class, no constructor
   IntUtilities();
};
