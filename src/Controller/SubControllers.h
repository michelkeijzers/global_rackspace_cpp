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
#ifdef TESTER
		  , Test
#endif
    };

    SubControllers(Controller& controller);
    ~SubControllers();

    void Fill();
    void Init();

    SubController &GetSubController(ESubControllerId id);

  private:
    std::vector<SubController *> _subControllers;
    
	 Controller& _controller;
};
