#pragma once

#include "Plugin.h"

class OrganPlugin : public Plugin
{
  public:
    OrganPlugin();
    OrganPlugin(std::string name);

	 void SetRotatorSpeedFast(bool fast);
};
