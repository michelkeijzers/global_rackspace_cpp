#include <iostream>
#include <string>

#include "Debug.h"


#ifdef _CONSOLE
    #include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/types.h"
#else
    #include "gigperformer/sdk/types.h"
#endif


/* static */ gigperformer::sdk::GigPerformerAPI *Debug::_gigPerformerApi = nullptr;
/* static */ bool Debug::_logHeaders = true;
/* static */ int Debug::_logMethodIndentation = 0;


/* static */ void Debug::Assert(bool condition, std::string functionName, std::string errorText)
{
    if (!condition)
    {
        std::cout << "ASSERT ERROR: " << functionName << ": " << errorText;
        //exit(1);
	 }
}


/* static */ void Debug::Log(std::string text)
{
    _gigPerformerApi->scriptLog(std::string(_logMethodIndentation, ' ') + text, true);
}


/* static */ void Debug::LogHeaders(bool logHeaders)
{
    _logHeaders = logHeaders;
}


/* static */ void Debug::LogMethodEntry(std::string methodName, std::string parameters)
{
	std::string text = std::string(_logMethodIndentation, ' ') + ">" + methodName + "(";

	if (parameters != "") 
	{
        text += parameters;
	}

	text += ")\n";
    _gigPerformerApi->scriptLog(text, true);

    _logMethodIndentation++;
}


/* static */ void Debug::LogMethodExit(std::string methodName, std::string parameters)
{
    _logMethodIndentation--;
    Debug::Assert(_logMethodIndentation >= 0, __FUNCTION__, "Debug _logMethodIntendation is negative");

	 std::string text = std::string(_logMethodIndentation, ' ') + "<" + methodName + "(";

    if (parameters != "")
    {
        text += parameters;
    }

    text += ")\n";
    _gigPerformerApi->scriptLog(text, true);
}


/* static */ void Debug::SetGigPerformerApi(gigperformer::sdk::GigPerformerAPI *gig_performer_api)
{
    _gigPerformerApi = gig_performer_api;
}
