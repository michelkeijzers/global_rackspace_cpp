#include "OrganPlugin.h"
#include "../Controller/Controller.h"
#include "../Utilities/BoolUtilities.h"
#include "../Utilities/Debug.h"
#include <iostream>
#include "../Framework/MvcFramework.h"

#ifdef _CONSOLE
    #include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/GigPerformerAPI.h"
#else
    #include <gigperformer/sdk/GigPerformerAPI.h>
#endif

OrganPlugin::OrganPlugin(Controller *controller) : Plugin("Organ", controller)
{
}

void OrganPlugin::SetDrawbarValue(int drawbarIndex, double newValue)
{
    Debug::LogMethodEntry(__FUNCTION__, "DrawbarIndex = " + std::to_string(drawbarIndex) +
                                            ", newValue = " + std::to_string(newValue));

	 MvcFramework::GetGigPerformerApi()->setPluginParameter(GetName(), 16 + drawbarIndex, newValue,
                                                              true); // TODO: Check number + make const

    Debug::LogMethodExit(__FUNCTION__);
}

void OrganPlugin::SetRotatorSpeedFast(bool fast)
{
    Debug::LogMethodEntry(__FUNCTION__, "fast: " + std::to_string(fast));

    MvcFramework::GetGigPerformerApi()->setPluginParameter(GetName(), 8, BoolUtilities::ToDouble(fast), true); // TODO: Make const

    Debug::LogMethodExit(__FUNCTION__);
}