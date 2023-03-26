#include "ArrayUtilities.h"
#include "Debug.h"

/* static */ std::string ArrayUtilities::ToHexString(const uint8_t *data, int length)
{
   std::string text = "";
   Debug::Assert(length >= 0, __FUNCTION__, "Invalid lenght");
   Debug::Assert(length < 256, __FUNCTION__, "Too many bytes");

   for (int index = 0; index < length; index++)
   {
      text += IntUtilities::ToHexString(data[index]);
      if (index < length - 1)
      {
         text += " ";
      }
   }
   return text;
}
