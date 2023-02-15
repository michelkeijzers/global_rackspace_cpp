#include "Plugin.h"

Plugin::Plugin()
{
}

Plugin::Plugin(std::string name)
{
    _name = name;
}

std::string Plugin::GetName()
{
    return _name;
}
