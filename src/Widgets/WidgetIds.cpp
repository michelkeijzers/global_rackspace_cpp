#include "WidgetIds.h"
#include "../Utilities/Debug.h"

WidgetIds::WidgetIds()
{
}

/// <summary>
/// Filles vector and map, use same order as EWidgetId order.
/// </summary>
void WidgetIds::Fill()
{
    _idToNames.push_back("Organ Drawbar 1 Slider");
    _idToNames.push_back("Organ Drawbar 2 Slider");

	Debug::Assert(_idToNames.size() == (int) WidgetIds::EWidgetId::Last, __FUNCTION__, "Widget ID list does not match");
}

WidgetIds::EWidgetId WidgetIds::GetId(std::string name)
{
    return _nameToIds[name];
}

std::string WidgetIds::GetName(EWidgetId id)
{
    return _idToNames[(int) id];
}
