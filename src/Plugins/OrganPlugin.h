#pragma once

#include "Plugin.h"

class Controller;

class OrganPlugin : public Plugin
{
  public:
    OrganPlugin(Controller *controller);

    void SetRotatorSpeedFast(bool fast);
};
