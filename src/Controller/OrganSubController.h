#pragma once

#include "../Model/organSubModel.h"
#include "SubController.h"

class Controller;
class OrganSubModel;

class OrganSubController : public SubController
{
  public:
    OrganSubController(Controller& controller);

	 void Init();

    void SetIsPresent(bool isPresent, bool forced = false);

	 void SetDrawbarValue(int drawbarIndex, double newValue, bool forced = false);

	 void SetRotatorSpeed(bool newRotatorSpeedFast, bool forced = false);
    void SwapRotatorSpeed();

	 void SetOverdrive(double overdrive, bool forced = false);
    void SetReverb(double reverb, bool forced = false);

  private:
    OrganSubModel &_organSubModel;
};
