#include "OrganPlugin.h"
#include "../Controller/Controller.h"
#include "../Utilities/BoolUtilities.h"
#include "../Utilities/Debug.h"
#include <iostream>

OrganPlugin::OrganPlugin(Controller *controller) : Plugin("Organ", controller)
{
}

void OrganPlugin::SetDrawbarValue(int drawbarIndex, double newValue)
{
    Debug::LogMethodEntry(__FUNCTION__, "DrawbarIndex = " + std::to_string(drawbarIndex) +
                                            ", newValue = " + std::to_string(newValue));

	 GetController()->GetGigPerformerAPI()->setPluginParameter(GetName(), 16 + drawbarIndex, newValue,
                                                              true); // TODO: Check number + make const

    Debug::LogMethodExit(__FUNCTION__);
}

void OrganPlugin::SetRotatorSpeedFast(bool fast)
{
    Debug::LogMethodEntry(__FUNCTION__, "fast: " + std::to_string(fast));

    GetController()->GetGigPerformerAPI()->setPluginParameter(GetName(), 8, BoolUtilities::ToDouble(fast), true); // TODO: Make const

    Debug::LogMethodExit(__FUNCTION__);
}