#include "Debug.h"
#include <algorithm>
#include <iostream>
#include <string>
#ifdef TESTER
#include "../../../JuceTester2/NewProject/Builds/VisualStudio2022/Source/GP_API/types.h"
#endif
#include <juce_core/juce_core.h>

const std::string JUCE_LOG_FILE_NAME = "D:\\JuceLogger\\JuceLogger.txt";

/* static */ bool Debug::_logHeaders = true;
/* static */ gigperformer::sdk::GigPerformerAPI *Debug::_gigPerformerApi = nullptr;
/* static */ int Debug::_logMethodIndentation = 0;
/* static */ juce::File *Debug::_logFile = nullptr;
/* static */ juce::FileLogger *Debug::_fileLogger = nullptr;

// For testing only
/* static */ std::vector<std::string> Debug::_testLog;
/* static */ std::string Debug::_testName = "";
/* static */ bool Debug::_testHasPassed = false;
/* static */ bool Debug::_loggingIsEnabled = true;
/* static */ bool Debug::_exitOnErrorIsEnabled = true;

/* static */ void Debug::Error(const std::string &functionName, const std::string &errorText)
{
   std::string message = "ERROR: " + functionName + ": " + errorText;
   LogToAll(message, true);
   Exit(1);
}

/* static */ void Debug::Warning(const std::string &functionName, const std::string &errorText)
{
   std::string message = "WARNING: " + functionName + ": " + errorText;
   LogToAll(message, true);
}

/* static */ void Debug::NotImplemented(const std::string &functionName)
{
   std::string message = "ERROR: " + functionName + " is not implemented";
   LogToAll(message);
   Exit(2);
}

/* static */ void Debug::Assert(bool condition, const std::string &functionName, const std::string &errorText)
{
   if (!condition)
   {
      std::string message = "ASSERT ERROR: " + functionName + ": " + errorText;
      LogToAll(message, true);
      Exit(3);
   }
}

/* static */ void Debug::Exit(int errorNumber)
{
#ifdef TESTER
   if (_exitOnErrorIsEnabled)
   {
      exit(errorNumber);
   }
#endif
}

/* static */ void Debug::Log(const std::string &text)
{
   std::string message = std::string(_logMethodIndentation, ' ') + text;
   LogToAll(message);
}

/* static */ void Debug::Log(const std::string &methodName, const std::string &text)
{
   const std::string message = std::string(_logMethodIndentation, ' ') + methodName + " : " + text;
   LogToAll(message);
}

/* static */ void Debug::LogHeaders(bool logHeaders)
{
   _logHeaders = logHeaders;
}

/* static */ void Debug::LogMethodEntry(
 const std::string &methodName, const std::string &parameters, const std::string &additionalText)
{
   if (!_logHeaders)
   {
      return;
   }
   std::string message = std::string(_logMethodIndentation, ' ') + ">" + methodName + "(";
   if (parameters != "")
   {
      message += parameters;
   }
   message += ")";
   if (additionalText != "")
   {
      message += ", " + additionalText;
   }
   LogToAll(message);
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
   std::string message = std::string(_logMethodIndentation, ' ') + "<" + methodName + "()";
   if (returnInfo != "")
   {
      message += ": " + returnInfo;
   }
   LogToAll(message);
}

/* static */ void Debug::SetGigPerformerApi(gigperformer::sdk::GigPerformerAPI *gig_performer_api)
{
   _gigPerformerApi = gig_performer_api;
}

Debug::Debug()
{
}

Debug::~Debug()
{
   if (_fileLogger != nullptr)
   {
      delete _fileLogger;
   }

   if (_logFile != nullptr)
   {
      delete _logFile;
   }
}

/* static */ void Debug::LogToAll(std::string message, bool forceLogging /* = false */)
{
   if ((_loggingIsEnabled) || (forceLogging))
   {
      if (_fileLogger == nullptr)
      {
         {
            _logFile = new juce::File(JUCE_LOG_FILE_NAME);
            _fileLogger = new juce::FileLogger(*_logFile, "LOG");
         }
      }
      _gigPerformerApi->scriptLog(message, true);
      _fileLogger->logMessage(message);
      _testLog.push_back(message);
   }
}

/* static */ void Debug::StartTest(const std::string &testName)
{
   _testName = testName;
   _testLog.clear();
   _testHasPassed = true;
}

/* static */ bool Debug::AssertTestLogContains(std::string line, int exactlyTimes /* = 1 */)
{
   int times = 0;
	for (int index = 0; index < _testLog.size(); index++)
	{
		if (_testLog[index] == line)
		{
         times++;
		}
	}
    bool ok = (times == exactlyTimes);
    Assert(ok, _testName,
     "Expected line: '" + line + " (expected times: " + std::to_string(exactlyTimes) +
      ", found: " + std::to_string(times) + " times)");
   _testHasPassed |= ok;
   return ok;
}

/* static */ bool Debug::AssertTestLogDoesNotContain(std::string line)
{
   bool found = std::find(_testLog.begin(), _testLog.end(), line) != _testLog.end();
   Assert(!found, _testName, "Unexpected line: '" + line + "'\n");
   _testHasPassed |= !found;
   return !found;
}

/* static */ bool Debug::CheckTestResult()
{
   LogToAll(_testHasPassed ? "----->Test passed" : "---->TEST FAILED");
   Assert(_testHasPassed, __FUNCTION__, "Test failed");
   return _testHasPassed;
}

/* static */ void Debug::EnableLogging(bool enable /* = true */)
{
   _loggingIsEnabled = enable;
}

/* static */ void Debug::DisableLogging()
{
   _loggingIsEnabled = false;
}

/* static */ void Debug::EnableExitOnError(bool enable /* = true */)
{
   _exitOnErrorIsEnabled = enable;
}

/* static */ void Debug::DisableExitOnError()
{
   _exitOnErrorIsEnabled = false;
}
