#include "ColorUtilities.h"

/* static i*/ uint32_t ColorUtilities::RgbaToColor(double red, double green, double blue, double alpha)
{
   int redInteger = static_cast<int>((red / 256.0) * 255.0 * 256.0);
   int greenInteger = static_cast<int>((green / 256.0) * 255.0 * 256.0);
   int blueInteger = static_cast<int>((blue / 256.0) * 255.0 * 256.0);
   int alphaInteger = static_cast<int>((alpha / 256.0) * 255.0 * 256.0);

   return (redInteger << 24) + (greenInteger << 16) + (blueInteger << 8) + alphaInteger;
}

/* static */ std::string ColorUtilities::ToColorString(uint32_t color)
{
   uint32_t castedColor = static_cast<uint32_t>(color);
   return std::to_string(castedColor / 256 / 256 / 256) + ", " +
          std::to_string((castedColor % (256 * 256 * 256)) / 256 / 256) + ", " +
          std::to_string((castedColor % (256 * 256)) / 256) + ", " + std::to_string(castedColor % 256);
}
