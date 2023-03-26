#pragma once

#include <string>

class ColorUtilities
{
 public:
   /// \brief  Converts red, green, blue and alpha to an uint32_t
   /// \param red color
   /// \param green color
   /// \param blue color
   /// \param alpha property
   /// \returns uint32_t with rgba
   static uint32_t RgbaToColor(double red, double green, double blue, double alpha);

   /// \brief  Converts int(32) to RGBA string.
   /// \param  value: color
   /// \return String in form (127, 128, 16, 63) in format (r, g, b, a)
   static std::string ToColorString(uint32_t color);

 private:
   /// \brief Utility class, no constructor
   ColorUtilities();
};
