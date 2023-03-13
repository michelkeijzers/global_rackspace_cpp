#include "Debug.h"
#include <iostream>
#include <string>
#ifdef WIN32
    #include "../../../JuceTest1/NewProject/Builds/VisualStudio2022/GP_API/types.h"
#endif
#include <juce_core/juce_core.h>

/* static */ gigperformer::sdk::GigPerformerAPI *Debug::_gigPerformerApi = nullptr;
/* static */ bool Debug::_logHeaders = true;
/* static */ int Debug::_logMethodIndentation = 0;

/* static */ void Debug::Error(const std::string &functionName, const std::string &errorText)
{
    std::string message = "ERROR: " + functionName + ": " + errorText;

#ifdef WIN32
    // std::cout << message;
    DBG(message);
    exit(1);
#endif
}

/* static */ void Debug::NotImplemented(const std::string &functionName)
{
    std::string message = "ERROR: " + functionName + " is not implemented";
#ifdef WIN32
    //std::cout << std::endl;
    DBG(message);
    exit(1);
#endif
}

/* static */ void Debug::Assert(bool condition, const std::string &functionName, const std::string &errorText)
{
    if (!condition)
    {
        std::string message = "ASSERT ERROR: " + functionName + ": " + errorText;
#ifdef WIN32
        DBG(message);
        exit(1);
#endif
    }
}

/* static */ void Debug::Log(const std::string &text)
{
    _gigPerformerApi->scriptLog(std::string(_logMethodIndentation, ' ') + text, true);
}

/* static */ void Debug::Log(const std::string &methodName, const std::string &text)
{
    const std::string fullText = std::string(_logMethodIndentation, ' ') + methodName + " : " + text;
    _gigPerformerApi->scriptLog(fullText, true);
}

/* static */ void Debug::LogHeaders(bool logHeaders)
{
    _logHeaders = logHeaders;
}

/* static */ void Debug::LogMethodEntry(const std::string &methodName, const std::string &parameters,
                                        const std::string &additionalText)
{
    if (!_logHeaders)
    {
        return;
    }

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

/* static */ void Debug::LogMethodExit(const std::string &methodName, const std::string &returnInfo)
{
    if (!_logHeaders)
    {
        return;
    }

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
