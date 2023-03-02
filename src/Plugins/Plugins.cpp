#include "Plugins.h"
#include "Plugin.h"

Plugins::Plugins() : _plugins()
{
}

Plugins::~Plugins()
{
    _plugins.clear();
}

void Plugins::AddPlugin(Plugin &plugin)
{
    _plugins.push_back(&plugin);
}
