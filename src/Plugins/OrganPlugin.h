#pragma once

#include "Plugin.h"

class Controller;

class OrganPlugin : public Plugin
{
  public:
    OrganPlugin(Controller *controller);

	 void SetDrawbarValue(int drawbarIndex, double newValue);
    void SetRotatorSpeedFast(bool fast);
};
