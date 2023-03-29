#include "IntUtilities.h"
#include "Debug.h"
#include <string>

/* static */ std::string IntUtilities::ToHexString(int value)
{
   Debug::Assert(value >= 0, __FUNCTION__, "Value too low");
   Debug::Assert(value < 0xFF, __FUNCTION__, "Value too high");
   static const char *digits = "0123456789ABCDEF";
   std::string valueAsHex = std::string(1, digits[value / 16]) + std::string(1, digits[value % 16]);
   return valueAsHex;
}

/* static */ bool IntUtilities::ToBool(int value)
{
   return value != 0;
}

/* static */ int IntUtilities::Map(int valueToMap, int inputMin, int inputMax, int outputMin, int outputMax)
{
   Debug::Assert(valueToMap >= inputMin, __FUNCTION__, "Value to map less than input minimum");
   Debug::Assert(valueToMap >= inputMax, __FUNCTION__, "Value to map higher than input maximum");
   Debug::Assert(inputMin < inputMax, __FUNCTION__, "Input minimum is higher or equal than input maximum");
   Debug::Assert(outputMin < outputMax, __FUNCTION__, "Output minimum is higher or equal than output maximum");
   return (outputMin + ((valueToMap - inputMin) / (inputMax - inputMin)) * (outputMax - outputMin));
}
