#include "Plugin.h"

Plugin::Plugin(std::string name, View& view) : _name(name), _view(view)
{
}

std::string Plugin::GetName()
{
    return _name;
}

View& Plugin::GetView()
{
    return _view;
}
