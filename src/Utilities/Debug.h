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
    static void Assert(bool condition, std::string functionName, std::string text);

    static void SetGigPerformerApi(gigperformer::sdk::GigPerformerAPI *gig_performer_api);

    static void Log(std::string text);

    static void LogHeaders(bool logHeaders);
    static void LogMethodEntry(std::string methodName, std::string parameters = "");
    static void LogMethodExit(std::string methodName, std::string parameters = "");

  private:
    Debug();

    static gigperformer::sdk::GigPerformerAPI *_gigPerformerApi;
    static bool _logHeaders;
    static int _logMethodIndentation;
};
