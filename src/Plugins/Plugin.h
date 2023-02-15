#pragma once

#include <string>

#include "gigperformer/sdk/types.h"

class Plugin
{
  public:
    Plugin();
    Plugin(std::string name);

    std::string GetName();

  private:
    std::string _name;
};
