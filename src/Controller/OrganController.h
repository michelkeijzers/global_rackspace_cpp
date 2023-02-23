#pragma once

#include <memory>
#include "../Model/Organ.h"

class Controller;
class OrganPlugin;

class OrganController
{
  public:
    OrganController(Controller* controller, std::shared_ptr<OrganPlugin> organPlugin);

	 void Init();

    void SetIsPresent(bool isPresent, bool forced = false);

	 void SetDrawbarValue(int drawbarIndex, double newValue, bool forced = false);

	 void SetRotatorSpeed(bool newRotatorSpeedFast, bool forced = false);
    void SwapRotatorSpeed();

  private:
    Controller* _controller; //TODO:  Make base class (Subcontroller? move this to subcontroller, same for Init virtual)
    std::shared_ptr<OrganPlugin> _organPlugin;
};
