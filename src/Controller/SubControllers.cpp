#include "SubControllers.h"

#include "../Utilities/Debug.h"
#include "KeyboardSubController.h"
#include "MixerSubController.h"
#include "OrganSubController.h"
#include "WindowSubController.h"
#ifdef TESTER
    #include "../../../JuceTester2/NewProject/Builds/VisualStudio2022/Source/TestFramework/TestController.h"
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
    _subControllers.push_back(new KeyboardSubController(_controller, true));
    _subControllers.push_back(new KeyboardSubController(_controller, false));
#ifdef TESTER
    _subControllers.push_back(new TestController(_controller));
#endif
    Debug::Assert(_subControllers.size() == (int)ESubControllerId::Last, __FUNCTION__, "Sub controller list incorrect");
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
