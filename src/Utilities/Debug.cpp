#include "Debug.h"
#include <iostream>
#include <string>
#ifdef _CONSOLE
    #include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/types.h"
#endif

/* static */ gigperformer::sdk::GigPerformerAPI *Debug::_gigPerformerApi = nullptr;
/* static */ bool Debug::_logHeaders = true;
/* static */ int Debug::_logMethodIndentation = 0;

/* static */ void Debug::Error(const std::string& functionName, const std::string& errorText)
{
    std::cout << "ERROR: " << functionName << ": " << errorText;
#ifdef _CONSOLE
    std::cout << std::endl;
#endif

    // exit(1);
}

/* static */ void Debug::Assert(bool condition, const std::string& functionName, const std::string& errorText)
{
    if (!condition)
    {
        std::cout << "ASSERT ERROR: " << functionName << ": " << errorText;
#ifdef _CONSOLE
        std::cout << std::endl;
#endif
        // exit(1);
    }
}

/* static */ void Debug::Log(const std::string& text)
{
    _gigPerformerApi->scriptLog(std::string(_logMethodIndentation, ' ') + text, true);
}

/* static */ void Debug::LogHeaders(bool logHeaders)
{
    _logHeaders = logHeaders;
}

/* static */ void Debug::LogMethodEntry(
	const std::string& methodName, const std::string& parameters, const std::string& additionalText)
{
    std::string text = std::string(_logMethodIndentation, ' ') + ">" + methodName + "(";

    if (parameters != "")
    {
        text += parameters;
    }

	 text += ")";

	 if (additionalText != "")
    {
         text += ", " + additionalText;
	 }

    _gigPerformerApi->scriptLog(text, true);
    _logMethodIndentation++;
}

/* static */ void Debug::LogMethodExit(const std::string& methodName, const std::string& returnInfo)
{
    _logMethodIndentation--;
    Debug::Assert(_logMethodIndentation >= 0, __FUNCTION__, "Debug _logMethodIntendation is negative");

    std::string text = std::string(_logMethodIndentation, ' ') + "<" + methodName + "()";

    if (returnInfo != "")
    {
        text += ": " + returnInfo;
    }

    _gigPerformerApi->scriptLog(text, true);
}

/* static */ void Debug::SetGigPerformerApi(gigperformer::sdk::GigPerformerAPI *gig_performer_api)
{
    _gigPerformerApi = gig_performer_api;
}
