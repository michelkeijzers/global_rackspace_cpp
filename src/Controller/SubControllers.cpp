#include "SubControllers.h"

#include "MixerSubController.h"
#include "OrganSubController.h"
#ifdef WIN32
	#include "../../../JuceTest1/NewProject/Builds/VisualStudio2022/Tester/TestController.h"
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
#ifdef WIN32
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
