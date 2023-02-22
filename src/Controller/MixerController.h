#pragma once

#include "../Model/Mixer.h"
//TODO #include "../Plugins/OrganPlugin.h"
#include <memory>

class Controller;

class MixerController
{
  public:
    MixerController(Controller *controller); // Add plugins.

    void Init();

  
  private:
    Controller *_controller;
    //TODO std::shared_ptr<OrganPlugin> _organPlugin;
};
