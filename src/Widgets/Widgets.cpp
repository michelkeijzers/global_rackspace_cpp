#include "Widgets.h"
#include "../Utilities/Debug.h"
#include <iostream>
#include <vector>

Widgets::Widgets()
{
}

void Widgets::AddWidget(std::shared_ptr<Widget> widget)
{
    _widgets.push_back(widget);
}
