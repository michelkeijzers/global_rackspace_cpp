#pragma once

#include <string>

#ifdef _CONSOLE
    #include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/types.h"
#else
    #include "gigperformer/sdk/types.h"
#endif

class Plugin
{
  public:
    Plugin();
    Plugin(std::string name);

    std::string GetName();

  private:
    std::string _name;
};
