#pragma once

#include "../Model/Organ.h"
#include "../Plugins/OrganPlugin.h"

class Controller;

class OrganController
{
  public:
    OrganController(Controller* controller, OrganPlugin* organPlugin);

    bool SwapRotatorSpeed();
    void UpdateIsPresent(bool isPresent);
    void UpdateRotatorSpeed(bool fast);

  private:
    Controller* _controller;
    OrganPlugin* _organPlugin;
};
