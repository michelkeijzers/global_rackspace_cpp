#pragma once

class BoolUtilities
{
  public:
    /// \brief  Converts a boolean to double (0.0, 1.0)
    /// \param  value: boolean to convert
    /// \return 0.0 if boolean is false, 1.0 if boolean is true
    static double ToDouble(bool value);

  private:
    /// \brief Utility class, no constructor
    BoolUtilities();
};
