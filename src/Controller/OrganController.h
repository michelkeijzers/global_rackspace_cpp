#pragma once

#include <memory>
#include "../Model/Organ.h"
#include "../Plugins/OrganPlugin.h"

class Controller;

class OrganController
{
  public:
    OrganController(Controller* controller, std::shared_ptr<OrganPlugin> organPlugin);

    bool SwapRotatorSpeed();
    void UpdateIsPresent(bool isPresent);
    void UpdateRotatorSpeed(bool fast, bool forced = false);

  private:
    Controller* _controller;
    std::shared_ptr<OrganPlugin> _organPlugin;
};
