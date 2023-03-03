#include "SubControllers.h"

#include "MixerSubController.h"
#include "OrganSubController.h"

//TODO: NOT USED YET

SubControllers::SubControllers(Controller &controller) : _controller(controller)
{
}

SubControllers::~SubControllers()
{
    _subControllers.clear();
}


void SubControllers::Fill()
{
    _subControllers.push_back(new MixerSubController(_controller));
    _subControllers.push_back(new OrganSubController(_controller));
}

void SubControllers::Init()
{
}

SubController &SubControllers::GetSubControllerById(ESubControllerId id)
{
    return *(_subControllers.at((int)id));
}
