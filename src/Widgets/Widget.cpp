#include "Widget.h"
#include "../Framework/MvcFramework.h"
#include "WidgetIds.h"

Widget::Widget(WidgetIds &widgetIds, WidgetIds::EWidgetId id, bool isListenedTo)
    : _widgetIds(widgetIds), _id(id), _isListenedTo(isListenedTo)
{
   if (isListenedTo)
   {
      MvcFramework::GetGigPerformerApi().listenForWidget(GetName(), true);
   }
}

WidgetIds::EWidgetId Widget::GetId() { return _id; }

std::string Widget::GetName() { return _widgetIds.GetName(_id); }

void Widget::Show(bool show /* = true */)
{
   MvcFramework::GetGigPerformerApi().setWidgetHideOnPresentation(GetName(), !show);
}

bool Widget::IsListenedTo() { return _isListenedTo; }
