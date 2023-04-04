#include "VersionUtilities.h"
#include "Debug.h"
#include "StringUtilities.h"

/* static */ bool VersionUtilities::IsBeforeOrEqual(std::string version1, std::string version2)
{
   int dot1 = version1.find('.');
   Debug::Assert((dot1 > 0) && (dot1 != std::string::npos), __FUNCTION__, "Illegal version " + version1);
   int majorVersion1 = StringUtilities::ParseInt(version1.substr(0, dot1), "Error parsing integer");
   int minorVersion1 = StringUtilities::ParseInt(version1.substr(dot1 + 1), "Error parsing integer");
   int dot2 = version2.find('.');
   Debug::Assert((dot2 > 0) && (dot2 != std::string::npos), __FUNCTION__, "Illegal version " + version2);
   int majorVersion2 = StringUtilities::ParseInt(version2.substr(0, dot2), "Error parsing integer");
   int minorVersion2 = StringUtilities::ParseInt(version2.substr(dot2 + 1), "Error parsing integer");
   return ((majorVersion1 < majorVersion2) || ((majorVersion1 == majorVersion2) && (minorVersion1 <= minorVersion2)));
}
