#include <iostream>

#include "OrganPlugin.h"
#include "../Utilities/Debug.h"
#include "../Utilities/BoolUtilities.h"
#include "../Controller/Controller.h"


OrganPlugin::OrganPlugin(Controller *controller) : Plugin(""), _controller(controller)
{
}


void OrganPlugin::SetRotatorSpeedFast(bool fast)
{
    Debug::LogMethodEntry(__FUNCTION__, "fast: " + std::to_string(fast));
	
	 _controller->GetGigPerformerAPI()->setPluginParameter("OrganPlugin", 8, BoolUtilities::ToDouble(fast), true);
	 
	 Debug::LogMethodExit(__FUNCTION__);
}