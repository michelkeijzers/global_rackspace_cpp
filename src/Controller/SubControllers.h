#pragma once

#include "MixerSubController.h"
#include "OrganSubController.h"

class Controller;

class SubControllers
{
  public:
    SubControllers(Controller& controller);
    MixerSubController& GetMixerSubController();
    OrganSubController& GetOrganSubController();
    void Init();

  private:
    MixerSubController _mixerSubController;
    OrganSubController _organSubController;
};
