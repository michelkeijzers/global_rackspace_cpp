#include <memory>
#include "Pane.h"
#include "../../Utilities/Debug.h"

Pane::Pane()
{
}

void Pane::AddWidgetName(std::string widgetName)
{
    _widgetNames.push_back(widgetName);
}

std::string Pane::GetWidgetNameByIndex(uint8_t index)
{
    Debug::Assert(index < _widgetNames.size(), __FUNCTION__, ": Widget index out of range");
    return _widgetNames[index];
}