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

Widget &Widgets::GetWidgetById(WidgetIds::EWidgetId id)
{
    return *(_widgets.at(id));
}