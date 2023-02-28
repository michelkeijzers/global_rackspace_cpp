#pragma once

#include <memory>

class Controller;
class MixerSubController;
class OrganSubController;

class SubControllers
{
  public:
    SubControllers(Controller *controller);
    std::shared_ptr<MixerSubController> GetMixerSubController();
    std::shared_ptr<OrganSubController> GetOrganSubController();
    void Init();

  private:
    std::shared_ptr<MixerSubController> _mixerSubController;
    std::shared_ptr<OrganSubController> _organSubController;
};
