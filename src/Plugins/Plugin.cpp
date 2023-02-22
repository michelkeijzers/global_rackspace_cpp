#include "Plugin.h"

Plugin::Plugin(std::string name, Controller *controller) : _name(name), _controller(controller)
{
}

std::string Plugin::GetName()
{
    return _name;
}

Controller *Plugin::GetController()
{
    return _controller;
}