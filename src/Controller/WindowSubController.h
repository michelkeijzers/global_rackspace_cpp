#pragma once

#include "../Model/MixerSubModel.h"
#include "SubController.h"

class WindowSubController : public SubController
{
  public:
    WindowSubController(Controller &controller);

    void SetNextSlidersPane();

  private:
    MixerSubModel &_mixerSubModel;
};
