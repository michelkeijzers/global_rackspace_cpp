#pragma once

#include <memory>
#include "../Model/Organ.h"
#include "../Plugins/OrganPlugin.h"

class Controller;

class OrganController
{
  public:
    OrganController(Controller* controller, std::shared_ptr<OrganPlugin> organPlugin);

    void SetIsPresent(bool isPresent);

	 void SetRotatorSpeed(bool newRotatorSpeedFast, bool forced = false);
    void SwapRotatorSpeed();

  private:
    Controller* _controller;
    std::shared_ptr<OrganPlugin> _organPlugin;
};
