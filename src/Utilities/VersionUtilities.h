#pragma once

#include <string>
#include <vector>

class VersionUtilities
{
   /// \brief Returns true when version1 is before or equal version2.
	/// \comment Only versions in format "x.y" are allowed.
	/// \param version1: first version to check
	/// \param version2: second version to check\
	/// \returns true if version1 is before or equal 2, else otherwise
 public:
   static bool IsBeforeOrEqual(std::string version1, std::string version2);

 private:
   VersionUtilities();
};
