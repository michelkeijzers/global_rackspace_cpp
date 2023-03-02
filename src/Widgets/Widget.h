#pragma once

#include "WidgetIds.h"
#include <string>

class WidgetIds;
class Widget
{
  public:
    WidgetIds::EWidgetId GetId();
    std::string GetName();
    bool IsListenedTo();

	protected:
    Widget(WidgetIds &widgetIds, WidgetIds::EWidgetId id, bool isListenedTo);

  private:
    WidgetIds::EWidgetId _id;
    bool _isListenedTo;
    WidgetIds& _widgetIds;
};