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
