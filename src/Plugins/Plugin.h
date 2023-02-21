#pragma once

#include <string>

class Plugin
{
  public:
    Plugin();
    Plugin(std::string name);

    std::string GetName();

  private:
    std::string _name;
};
