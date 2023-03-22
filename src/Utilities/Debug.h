#pragma once

#include <juce_core/juce_core.h>
#include <juce_core/files/juce_File.h>
#include <juce_core/logging/juce_FileLogger.h>
#include <vector>
#ifdef TESTER
    #include "../../../JuceTester2/NewProject/Builds/VisualStudio2022/Source/GP_API/GigPerformerAPI.h"
#else
    #include "../../build/windows-native/_deps/gp-sdk-src/CPP/include/gigperformer/sdk/GigPerformerAPI.h"
#endif

class Debug
{
  public:
    /// \brief Displays error, but continues run
    /// \param functionName: name of the function to print
    /// \param text: text to print
    static void Error(const std::string &functionName, const std::string &text);

    /// <summary>
    /// \brief Displays error that a function is not implemented.
    /// \param functionName: name of the function to print
    /// </summary>
    /// <param name="functionName"></param>
    static void NotImplemented(const std::string &functionName);

    /// \brief Displays error, but continues run
    /// \param condition: boolean to be checked, if false, error is printed
    /// \param functionName: name of the function to print
    /// \param text: text to print
    static void Assert(bool condition, const std::string &functionName, const std::string &text);

    /// \brief Sets GP library to print to console, need to be executed before other calls are done
    static void SetGigPerformerApi(gigperformer::sdk::GigPerformerAPI *gig_performer_api);

    /// \brief Text to log.
    static void Log(const std::string &text);

    /// \brief Text to log.
    /// \param methodName: name of the method
    static void Log(const std::string &methodName, const std::string &text);

    /// \brief Sets boolean if header entries and exits are logged, default true.
    /// \param logHeaders: boolean to activate/deactivate printing of headers
    static void LogHeaders(bool logHeaders);

    /// \brief Prints a method entry logging
    /// \param methodName: name of the method
    /// \param parameters: optional parameter list to be printed
    /// \param additionalText: more text that is added after the prototype
    static void LogMethodEntry(const std::string &methodName, const std::string &parameters = "",
                               const std::string &additionalText = "");

    /// \brief Prints a method entry logging
    /// \param methodName: name of the method
    /// \param returnInfo: optional return or other values (as string) to be printed
    static void LogMethodExit(const std::string &methodName, const std::string &returnInfo = "");

    /// \brief Only for testing; starts test
    /// \param testName: name of test
    static void StartTest(const std::string &testName);

    /// \brief Only for testing; checks if the log (since the start of the last test contain the line exactly)
    /// \param line: line to check
    /// \return True if found, false otherwise
    static bool AssertTestLogContains(std::string line);

    /// \brief Only for testing; checks test result
	 /// \returns True if passed, false if failed
    static bool CheckTestResult();

  private:
    Debug();
    ~Debug();

    static void LogToAll(std::string message);

    static gigperformer::sdk::GigPerformerAPI *_gigPerformerApi;
    static bool _logHeaders;
    static int _logMethodIndentation;

    static juce::File *_logFile;
    static juce::FileLogger *_fileLogger;

    // For testing only
    static std::string _testName;
    static bool _testPassed;
    static std::vector<std::string> _testLog;
};
