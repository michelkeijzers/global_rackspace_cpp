#include "Widgets.h"
#include "../Utilities/Debug.h"
#include <iostream>
#include <vector>
#include "WidgetIds.h"

Widgets::Widgets()
{
}

Widgets::~Widgets()
{
    _widgets.clear();
} 

void Widgets::AddWidget(WidgetIds::EWidgetId id, Widget * widget)
{
    _widgets.insert(std::pair<WidgetIds::EWidgetId, Widget *>(id, widget));
}

Widget &Widgets::GetWidget(WidgetIds::EWidgetId id, int offset /* = 0 */)
{
    return *(_widgets.at((WidgetIds::EWidgetId)(static_cast<int>(id) + offset)));
}

std::vector<WidgetIds::EWidgetId> Widgets::GetWidgetIds()
{
    std::vector<WidgetIds::EWidgetId> widgetIds;
    for (auto &iterator : _widgets)
	 {
        widgetIds.push_back(iterator.first);
	 }
     return widgetIds;
}
