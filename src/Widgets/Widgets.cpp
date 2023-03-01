#include "Widgets.h"
#include "../Utilities/Debug.h"
#include <iostream>
#include <vector>
#include "WidgetIds.h"

Widgets::Widgets()
{
}

void Widgets::AddWidget(WidgetIds::EWidgetId id, std::shared_ptr<Widget> widget)
{
    _widgets.insert(std::pair<WidgetIds::EWidgetId, std::shared_ptr<Widget>>(id, widget));
}

Widget &Widgets::GetWidgetById(WidgetIds::EWidgetId id)
{
    return *(_widgets.at(id));
}