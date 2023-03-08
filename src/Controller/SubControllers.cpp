#include "SubControllers.h"

#include "MixerSubController.h"
#include "OrganSubController.h"
#ifdef _CONSOLE
	#include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/TestController.h"
#endif

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
#ifdef _CONSOLE
    _subControllers.push_back(new TestController(_controller));
#endif
}

void SubControllers::Init()
{
    for (auto subController : _subControllers)
    {
        subController->Init();
	 }
}

SubController &SubControllers::GetSubController(ESubControllerId id)
{
    return *(_subControllers.at((int)id));
}
