#include "SubControllers.h"

#include "MixerSubController.h"
#include "OrganSubController.h"

SubControllers::SubControllers(Controller *controller)
{
    _mixerSubController = std::make_shared<MixerSubController>(controller);
    _organSubController = std::make_shared<OrganSubController>(controller);
}

std::shared_ptr<MixerSubController> SubControllers::GetMixerSubController()
{
    return _mixerSubController;
}

std::shared_ptr<OrganSubController> SubControllers::GetOrganSubController()
{
    return _organSubController;
}

void SubControllers::Init()
{
    _mixerSubController->Init();
    _organSubController->Init();
}
