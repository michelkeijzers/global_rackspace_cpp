#pragma once

#include <memory>
#include "../Model/organSubModel.h"
#include "SubController.h"

class Controller;
class OrganPlugin;

class OrganSubController : SubController
{
  public:
    OrganSubController(Controller* controller);

	 void Init();

    void SetIsPresent(bool isPresent, bool forced = false);

	 void SetDrawbarValue(int drawbarIndex, double newValue, bool forced = false);

	 void SetRotatorSpeed(bool newRotatorSpeedFast, bool forced = false);
    void SwapRotatorSpeed();

  private:
    //std::shared_ptr<OrganPlugin> _organPlugin;
};
