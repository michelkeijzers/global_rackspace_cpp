#include <iostream>
#include "OrganPlugin.h"

OrganPlugin::OrganPlugin() : Plugin("")
{
}

OrganPlugin::OrganPlugin(std::string name) : Plugin(name)
{
}


void OrganPlugin::SetRotatorSpeedFast(bool fast)
{
    std::cout << "OrganPlugin::SetRotatorSpeedFast: " << fast << "\n";
	
	// SetPluginParameter(plugin, parameternumber, fast ? 127 : 0);
}