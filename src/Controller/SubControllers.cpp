#include "SubControllers.h"

#include "MixerSubController.h"
#include "OrganSubController.h"

SubControllers::SubControllers(Controller& controller)
    : _mixerSubController(controller), _organSubController(controller)
{
}

MixerSubController& SubControllers::GetMixerSubController()
{
    return _mixerSubController;
}

OrganSubController& SubControllers::GetOrganSubController()
{
    return _organSubController;
}

void SubControllers::Init()
{
    _mixerSubController.Init();
    _organSubController.Init();
}
