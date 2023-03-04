#pragma once

#include "MixerSubController.h"
#include "OrganSubController.h"
#include <vector>

class Controller;

class SubControllers
{
  public:
    enum class ESubControllerId
    {
        Mixer,
        Organ
#ifdef _CONSOLE
		  , Test
#endif
    };

    SubControllers(Controller& controller);
    ~SubControllers();

    void Fill();
    void Init();

    SubController &GetSubControllerById(ESubControllerId id);

  private:
    std::vector<SubController *> _subControllers;
    
	 Controller& _controller;
};
