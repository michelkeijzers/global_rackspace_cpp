#include "SubControllers.h"

#include "MixerSubController.h"
#include "OrganSubController.h"
#include "WindowSubController.h"
#include "KeyboardSubController.h"
#ifdef TESTER
	#include "../../../JuceTester2/NewProject/Source/TestController.h"
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
    _subControllers.push_back(new WindowSubController(_controller));
    _subControllers.push_back(new KeyboardSubController(_controller, false));
    _subControllers.push_back(new KeyboardSubController(_controller, true));

#ifdef TESTER
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
