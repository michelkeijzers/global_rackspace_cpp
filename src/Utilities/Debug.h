#pragma once

#include <vector>
#ifdef _CONSOLE
    #include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/GigPerformerAPI.h"
#else
    #include <gigperformer/sdk/GigPerformerAPI.h>
#endif

class Debug
{
  public:
    /// \brief Displays error, but continues run
    /// \param functionName: name of the function to print
    /// \param text: text to print
    static void Error(const std::string& functionName, const std::string& text);

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
    static void Assert(bool condition, const std::string& functionName, const std::string& text);

    /// \brief Sets GP library to print to console, need to be executed before other calls are done
    static void SetGigPerformerApi(gigperformer::sdk::GigPerformerAPI *gig_performer_api);

    /// \brief Text to log.
    static void Log(const std::string &text);

    /// \brief Text to log.
    /// \param methodName: name of the method
    static void Log(const std::string& methodName, const std::string &text);

    /// \brief Sets boolean if header entries and exits are logged, default true.
    /// \param logHeaders: boolean to activate/deactivate printing of headers
    static void LogHeaders(bool logHeaders);

    /// \brief Prints a method entry logging
    /// \param methodName: name of the method
    /// \param parameters: optional parameter list to be printed
	 /// \param additionalText: more text that is added after the prototype
    static void LogMethodEntry(const std::string& methodName, const std::string& parameters = "",
                               const std::string& additionalText = "");

    /// \brief Prints a method entry logging
    /// \param methodName: name of the method
    /// \param returnInfo: optional return or other values (as string) to be printed
    static void LogMethodExit(const std::string& methodName, const std::string& returnInfo = "");

  private:
    Debug();

    static gigperformer::sdk::GigPerformerAPI *_gigPerformerApi;
    static bool _logHeaders;
    static int _logMethodIndentation;
};
