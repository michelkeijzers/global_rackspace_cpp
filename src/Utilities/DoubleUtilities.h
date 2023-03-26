#pragma once

class DoubleUtilities
{
 public:
   /// \brief  Returns true if doubles are (almost) equal
   /// \param  value1: first double to check
   /// \param  value2: second double to check
   /// \return true if equal, false otherwise
   static double AreEqual(double value1, double value2);

   /// \brief  Returns true if doubles are (almost) equal
   /// \param  value1: first double to check
   /// \param  value2: second double to check
   /// \param  difference: max allowed difference (optional, otherwise use SetDifferentEquality)
   /// \return true if equal, false otherwise
   static double AreEqual(double value1, double value2, double valueEquality);

   /// <summary>
   /// \brief Returns the value used for checking the equality of doubles
   /// \return value for equality checking
   /// </summary>
   /// <returns></returns>
   static double GetMaximumEqualityDifference();

   /// <summary>
   /// \brief Sets the value used for checking the equality of doubles
   /// \param valueEquality : value for equality checking
   /// </summary>
   /// <param name="valueEquality"></param>
   static void SetMaximumEqualityDifference(double valueEquality);

 private:
   static double _maximumEqualityDifference;

   /// \brief Utility class, no constructor
   DoubleUtilities();
};
