#include "DoubleUtilities.h"
#include "Debug.h"

/* static */ double DoubleUtilities::_maximumEqualityDifference;

DoubleUtilities::DoubleUtilities() {}

/* static */ double DoubleUtilities::DoubleUtilities::AreEqual(double value1, double value2)
{
   return (fabs(value1 - value2) <= _maximumEqualityDifference);
}

/* static */ double DoubleUtilities::DoubleUtilities::AreEqual(double value1, double value2, double equalityDifference)
{
   return (fabs(value1 - value2) <= equalityDifference);
}

/* static */ double DoubleUtilities::GetMaximumEqualityDifference() { return _maximumEqualityDifference; }

/* static */ void DoubleUtilities::SetMaximumEqualityDifference(double maximumEqualityDifference)
{
   Debug::Assert(maximumEqualityDifference > 0.0, __FUNCTION__, "MaximumEqualityDifference is 0.0 or negative");
   Debug::Assert(maximumEqualityDifference < 1.0, __FUNCTION__, "MaximumEqualityDifference is lower than 1.0");
   _maximumEqualityDifference = maximumEqualityDifference;
}
