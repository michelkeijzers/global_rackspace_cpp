#include "Pane.h"
#include "../../Utilities/Debug.h"

Pane::Pane()
{
}

void Pane::AddWidget(std::string widgetName)
{
    _widgets.push_back(new Widget(widgetName));
}

Widget* Pane::GetWidgetByIndex(uint8_t index)
{
    Debug::Assert(index < _widgets.size(), __FUNCTION__, ": Widget index out of range");
    return _widgets[index];
}