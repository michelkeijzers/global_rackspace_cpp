#include <iostream>

#include "OrganPlugin.h"
#include "../Controller/Controller.h"


OrganPlugin::OrganPlugin(Controller *controller) : Plugin(""), _controller(controller)
{
}


void OrganPlugin::SetRotatorSpeedFast(bool fast)
{
    std::cout << "OrganPlugin::SetRotatorSpeedFast: " << fast << "\n";
	
	 _controller->GetGigPerformerAPI()->setPluginParameter("OrganPlugin", 8, fast ? 1.0 : 0.0, true);
    
	 //SetPluginParameter(plugin, parameternumber, fast ? 127 : 0);
}