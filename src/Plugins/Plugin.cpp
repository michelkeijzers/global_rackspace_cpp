#include "Plugin.h"

Plugin::Plugin(const std::string &name, View &view) : _name(name), _view(view)
{
}

void Plugin::Init()
{
}

const std::string Plugin::GetName()
{
   return _name;
}

View &Plugin::GetView()
{
   return _view;
}
